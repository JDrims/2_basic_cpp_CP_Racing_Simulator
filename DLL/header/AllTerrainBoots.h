#pragma once
#include <GroundVehicle.h>

class DLL_API AllTerrainBoots : public GroundVehicle {
private:
    static constexpr double SPEED = 6.0;
    static constexpr double TIME_MOVEMENT = 60.0;
    static constexpr double FIRST_REST = 10.0;
    static constexpr double ORDER_REST = 5.0;

public:
    std::string getName() const override { return "Ботинки-вездеходы"; }
    double getSpeed() const { return SPEED; }
    double getRestTime(double distance) const override;
};