#include "Broom.h"

double Broom::getAccelerationFactor(double distance) const {
    int thousands = static_cast<int>(distance / 1000.0);
    double factor = thousands * 0.01;
    if (factor > 0.9) factor = 0.9;
    return factor;
}