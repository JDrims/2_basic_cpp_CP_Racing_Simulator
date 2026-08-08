#include <AirVehicle.h>

double AirVehicle::calculateTime(double distance) const {
    double factor = getAccelerationFactor(distance);
    double reducedDistance = distance * (1.0 - factor);
    return reducedDistance / getSpeed();
}