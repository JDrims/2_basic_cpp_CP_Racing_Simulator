#pragma once
#include <AirVehicle.h>

class DLL_API MagicCarpet : public AirVehicle {
private:
    static constexpr double SPEED = 10.0;

public:
    std::string getName() const override { return "Ковёр-самолёт"; }
    double getSpeed() const override { return SPEED; }
    double getAccelerationFactor(double distance) const override;
};