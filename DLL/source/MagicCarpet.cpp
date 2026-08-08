#include "MagicCarpet.h"

double MagicCarpet::getAccelerationFactor(double distance) const {
    if (distance < 1000) {
        return 0.0;
    }
    else if (distance < 5000) {
        return 0.03;
    }
    else if (distance < 10000) {
        return 0.10;
    }
    else {
        return 0.05;
    }
}