#include "AirRace.h"
#include "AirVehicle.h"

bool AirRace::isVehicleAllowed(const Vehicle* vehicle) const {
    return dynamic_cast<const AirVehicle*>(vehicle) != nullptr;
}

bool AirRace::addVehicle(Vehicle* vehicle) {
    if (!isVehicleAllowed(vehicle)) {
        return false;
    }
    participants.push_back(std::unique_ptr<Vehicle>(vehicle));
    return true;
}