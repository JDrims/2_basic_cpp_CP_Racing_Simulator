#pragma once
#include <GroundVehicle.h>

class DLL_API AllTerrainBoots : public GroundVehicle {
private:
    static constexpr double SPEED = 6.0;
    static constexpr double REST_INTERVAL = 60.0;
    static constexpr double REST_DURATION = 10.0;

public:
    std::string getName() const override { return "Ботинки-вездеходы"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};