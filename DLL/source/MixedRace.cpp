#include "MixedRace.h"

bool MixedRace::isVehicleAllowed(const Vehicle* vehicle) const {
    return true;
}

bool MixedRace::addVehicle(Vehicle* vehicle) {
    participants.push_back(std::unique_ptr<Vehicle>(vehicle));
    return true;
}