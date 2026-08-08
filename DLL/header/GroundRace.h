#pragma once
#include "Race.h"

class DLL_API GroundRace : public Race {
public:
    explicit GroundRace(double dist) : Race(dist) {}

    bool addVehicle(Vehicle* vehicle) override;

protected:
    bool isVehicleAllowed(const Vehicle* vehicle) const override;
};