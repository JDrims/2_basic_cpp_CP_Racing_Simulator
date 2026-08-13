#include "Camel.h"

double Camel::getRestTime(double distance) const {
    const double interval = SPEED * TIME_MOVEMENT;
    int fullSegments = static_cast<int>(distance / interval);
    double rem = distance - fullSegments * interval;
    int stops = (rem == 0.0) ? fullSegments - 1 : fullSegments;
    if (stops < 0) stops = 0;
    if (stops == 0) return 0.0;
    return FIRST_REST + (stops - 1) * ORDER_REST;
}