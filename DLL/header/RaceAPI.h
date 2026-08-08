#pragma once

#ifdef RACE_LIBRARY_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <cstddef>

extern "C" {
    DLL_API void* createRace(int type, double distance);
    DLL_API bool addVehicle(void* race, int numVehicle);
    DLL_API bool removeVehicle(void* race, int numVehicle);
    DLL_API int getVehicleCount(void* race);
    DLL_API void startRace(void* race);
    DLL_API const char* getResults(void* race);
    DLL_API void freeResult(const char* result);
    DLL_API void destroyRace(void* race);
    DLL_API const char** getAvailableVehicles(int& count);
    DLL_API void freeAvailableVehicles(const char** list, int count);
    DLL_API const char** getRegisteredVehicles(void* race, int& count);
    DLL_API void freeStringArray(const char** list, int count);
    DLL_API const char* getNameByNumVehicles(int numVehicles);
}