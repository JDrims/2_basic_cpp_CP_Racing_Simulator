#pragma once
#include <GroundVehicle.h>

class DLL_API SpeedCamel : public GroundVehicle {
private:
    static constexpr double SPEED = 15.0;
    static constexpr double REST_INTERVAL = 20.0;
    static constexpr double REST_DURATION = 8.0;

public:
    std::string getName() const override { return "Верблюд-быстроход"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};