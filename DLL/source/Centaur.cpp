#include "Centaur.h"

double Centaur::getRestTime(double distance) const {
    const double interval = SPEED * TIME_MOVEMENT;
    int fullSegments = static_cast<int>(distance / interval);
    double rem = distance - fullSegments * interval;
    int stops = (rem == 0.0) ? fullSegments - 1 : fullSegments;
    if (stops < 0) stops = 0;
    return stops * FIRST_REST;
}