#include <GroundVehicle.h>

double GroundVehicle::calculateTime(double distance) const {
    double travelTime = distance / getSpeed();
    double restTime = getRestTime(distance);
    return travelTime + restTime;
}