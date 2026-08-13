#pragma once
#include <GroundVehicle.h>

class DLL_API SpeedCamel : public GroundVehicle {
private:
    static constexpr double SPEED = 40.0;
    static constexpr double TIME_MOVEMENT = 10.0;
    static constexpr double FIRST_REST = 5.0;
    static constexpr double SECOND_REST = 6.5;
    static constexpr double ORDER_REST = 8.0;

public:
    std::string getName() const override { return "Верблюд-быстроход"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};