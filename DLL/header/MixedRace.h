#pragma once
#include "Race.h"

class DLL_API MixedRace : public Race {
public:
    explicit MixedRace(double dist) : Race(dist) {}

    bool addVehicle(Vehicle* vehicle) override;

protected:
    bool isVehicleAllowed(const Vehicle* vehicle) const override;
};