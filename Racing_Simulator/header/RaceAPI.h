#pragma once

#ifdef RACE_LIBRARY_EXPORTS
#define RACE_API __declspec(dllexport)
#else
#define RACE_API __declspec(dllimport)
#endif

#include <cstddef>

namespace lib {
    extern "C" {
        RACE_API void* createRace(int type, double distance);
        RACE_API bool addVehicle(void* race, const char* name);
        RACE_API bool removeVehicle(void* race, const char* name);
        RACE_API int getVehicleCount(void* race);
        RACE_API void startRace(void* race);
        RACE_API const char* getResults(void* race);
        RACE_API void freeResult(const char* result);
        RACE_API void destroyRace(void* race);
        RACE_API const char** getAvailableVehicles(int& count);
        RACE_API void freeAvailableVehicles(const char** list, int count);
    }
}