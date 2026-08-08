#include "AllTerrainBoots.h"

double AllTerrainBoots::getRestTime(double distance) const {
    int stops = static_cast<int>(distance / REST_INTERVAL);
    return stops * REST_DURATION;
}