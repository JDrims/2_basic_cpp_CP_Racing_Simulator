#include "RaceAPI.h"
#include "Race.h"
#include "GroundRace.h"
#include "AirRace.h"
#include "MixedRace.h"
#include "Camel.h"
#include "SpeedCamel.h"
#include "Centaur.h"
#include "AllTerrainBoots.h"
#include "Eagle.h"
#include "MagicCarpet.h"
#include "Broom.h"

#include <TypeDef.h>
#include <vector>
#include <string>
#include <cstring>

static Vehicle* createVehicleByNum(int numVehicle) {
    switch (static_cast<tVehicle>(numVehicle))
    {
    case tVehicle::Camel:               return new Camel();
    case tVehicle::SpeedCamel:          return new SpeedCamel();
    case tVehicle::Centaur:             return new Centaur();
    case tVehicle::AllTerrainBoots:     return new AllTerrainBoots();
    case tVehicle::Eagle:               return new Eagle();
    case tVehicle::MagicCarpet:         return new MagicCarpet();
    case tVehicle::Broom:               return new Broom();
    }
    return nullptr;
}

extern "C" {

    void* createRace(int typeRace, double distance) {
        Race* race = nullptr;
        switch (static_cast<tRace>(typeRace)) {
        case tRace::GROUND:             race = new GroundRace(distance); break;
        case tRace::AERIAL:             race = new AirRace(distance); break;
        case tRace::GROUND_AND_AERIAL:  race = new MixedRace(distance); break;
        default: return nullptr;
        }
        return static_cast<void*>(race);
    }

    bool addVehicle(void* racePtr, int numVehicle) {
        if (!racePtr || !(0 <= numVehicle)) return false;
        Race* race = static_cast<Race*>(racePtr);
        Vehicle* vehicle = createVehicleByNum(numVehicle);
        if (!vehicle) return false;
        return race->addVehicle(vehicle);
    }

    bool removeVehicle(void* racePtr, int numVehicle) {
        if (!racePtr || !(0 <= numVehicle)) return false;
        Race* race = static_cast<Race*>(racePtr);
        return race->removeVehicle(numVehicle - 1);
    }

    int getVehicleCount(void* racePtr) {
        if (!racePtr) return 0;
        Race* race = static_cast<Race*>(racePtr);
        return race->getParticipantCount();
    }

    void startRace(void* racePtr) {
        if (!racePtr) return;
        Race* race = static_cast<Race*>(racePtr);
        race->start();
    }

    const char* getResults(void* racePtr) {
        if (!racePtr) return nullptr;
        Race* race = static_cast<Race*>(racePtr);
        auto results = race->getResults();

        int count = static_cast<int>(results.size());
        std::string strResult("");
        const char** list = new const char* [count];
        for (int i = 0; i < count; ++i) {
            strResult += std::to_string(i + 1) + ". " + results[i].first + ". Время: " + std::to_string(results[i].second);
            if (i < count - 1) strResult += "\n";
        }
        char* buffer = new char[strResult.size() + 1];
        strcpy(buffer, strResult.c_str());
        return buffer;
    }

    void freeResult(const char* result) {
        delete[] result;
    }

    void destroyRace(void* racePtr) {
        if (!racePtr) return;
        Race* race = static_cast<Race*>(racePtr);
        delete race;
    }

    const char** getAvailableVehicles(int& count) {
        count = static_cast<int>(g_availableVehicles.size());
        const char** list = new const char* [count];
        for (int i = 0; i < count; ++i) {
            list[i] = g_availableVehicles[i].nameVehicle.c_str();
        }
        return list;
    }

    void freeAvailableVehicles(const char** list, int count) {
        delete[] list;
    }

    const char** getRegisteredVehicles(void* racePtr, int& count) {
        if (!racePtr) {
            count = 0;
            return nullptr;
        }

        Race* race = static_cast<Race*>(racePtr);
        auto names = race->getParticipantNames();

        count = static_cast<int>(names.size());
        if (count == 0) {
            return nullptr;
        }

        const char** list = new const char* [count];
        for (int i = 0; i < count; ++i) {
            char* buffer = new char[names[i].size() + 1];
            strcpy(buffer, names[i].c_str());
            list[i] = buffer;
        }
        return list;
    }

    void freeStringArray(const char** list, int count) {
        if (!list) return;
        for (int i = 0; i < count; ++i) {
            delete[] list[i];
        }
        delete[] list;
    }

    const char* getNameByNumVehicles(int numVehicles) {
        for (const auto& vehicle : g_availableVehicles) {
            if (static_cast<int>(vehicle.typeVehicle) == numVehicles) {
                return vehicle.nameVehicle.c_str();
            }
        }
        return nullptr;
    }
}