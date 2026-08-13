#pragma once
#include <GroundVehicle.h>

class DLL_API Centaur : public GroundVehicle {
private:
    static constexpr double SPEED = 15.0;
    static constexpr double TIME_MOVEMENT = 8.0;
    static constexpr double FIRST_REST = 2.0;
    static constexpr double ORDER_REST = 2.0;

public:
    std::string getName() const override { return "Кентавр"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};