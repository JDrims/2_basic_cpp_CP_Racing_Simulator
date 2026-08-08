#pragma once
#include <AirVehicle.h>

class DLL_API Broom : public AirVehicle {
private:
    static constexpr double SPEED = 20.0;

public:
    std::string getName() const override { return "Метла"; }
    double getSpeed() const override { return SPEED; }
    double getAccelerationFactor(double distance) const override;
};