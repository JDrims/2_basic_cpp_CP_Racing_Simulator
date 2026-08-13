#include "SpeedCamel.h"

double SpeedCamel::getRestTime(double distance) const {
    const double interval = SPEED * TIME_MOVEMENT;
    int fullSegments = static_cast<int>(distance / interval);
    double rem = distance - fullSegments * interval;
    int stops = (rem == 0.0) ? fullSegments - 1 : fullSegments;
    if (stops < 0) stops = 0;
    if (stops == 0) return 0.0;
    double total = 0.0;
    for (int i = 0; i < stops; ++i) {
        if (i == 0) total += FIRST_REST;
        else if (i == 1) total += SECOND_REST;
        else total += ORDER_REST;
    }
    return total;
}