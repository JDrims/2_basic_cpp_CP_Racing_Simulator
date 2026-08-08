#pragma once

#ifdef RACE_LIBRARY_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include <string>

class DLL_API Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual std::string getName() const = 0;
    virtual double calculateTime(double distance) const = 0;
};