#include "GroundRace.h"
#include "GroundVehicle.h"

bool GroundRace::isVehicleAllowed(const Vehicle* vehicle) const {
    return dynamic_cast<const GroundVehicle*>(vehicle) != nullptr;
}

bool GroundRace::addVehicle(Vehicle* vehicle) {
    if (!isVehicleAllowed(vehicle)) {
        return false;
    }
    participants.push_back(std::unique_ptr<Vehicle>(vehicle));
    return true;
}