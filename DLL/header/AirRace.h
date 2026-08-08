#pragma once
#include "Race.h"

class DLL_API AirRace : public Race {
public:
    explicit AirRace(double dist) : Race(dist) {}

    bool addVehicle(Vehicle* vehicle) override;

protected:
    bool isVehicleAllowed(const Vehicle* vehicle) const override;
};