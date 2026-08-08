#pragma once
#include <AirVehicle.h>

class DLL_API Eagle : public AirVehicle {
private:
    static constexpr double SPEED = 8.0;

public:
    std::string getName() const override { return "Îð¸ë"; }
    double getSpeed() const override { return SPEED; }
    double getAccelerationFactor(double distance) const override { return 0.06; }
};