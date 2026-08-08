#pragma once
#include <GroundVehicle.h>

class DLL_API Camel : public GroundVehicle {
private:
    static constexpr double SPEED = 10.0;
    static constexpr double REST_INTERVAL = 30.0;
    static constexpr double REST_DURATION = 5.0;

public:
    std::string getName() const override { return "Верблюд"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};