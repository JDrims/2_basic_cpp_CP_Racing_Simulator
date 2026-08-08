#pragma once
#include <Vehicle.h>

class DLL_API AirVehicle : public Vehicle {
public:
    virtual double getAccelerationFactor(double distance) const = 0;
    virtual double getSpeed() const = 0;
    double calculateTime(double distance) const override;
};