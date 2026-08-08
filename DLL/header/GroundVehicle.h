#pragma once
#include "Vehicle.h"

class DLL_API GroundVehicle : public Vehicle {
public:
    virtual double getRestTime(double distance) const = 0;
    virtual double getSpeed() const = 0;
    double calculateTime(double distance) const override;
};