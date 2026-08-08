#include "Camel.h"

double Camel::getRestTime(double distance) const {
    int stops = static_cast<int>(distance / REST_INTERVAL);
    return stops * REST_DURATION;
}