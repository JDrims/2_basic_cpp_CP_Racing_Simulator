#pragma once
#include <GroundVehicle.h>

class DLL_API Centaur : public GroundVehicle {
private:
    static constexpr double SPEED = 8.0;

public:
    std::string getName() const override { return "Кентавр"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override { return 0.0; }
};