#pragma once
#include <string>
#include <vector>

enum class tRace {
    NONE = 0,
    GROUND = 1,
    AERIAL = 2,
    GROUND_AND_AERIAL = 3
};

enum class tVehicle {
    Camel = 1,
    SpeedCamel,
    Centaur,
    AllTerrainBoots,
    Eagle,
    MagicCarpet,
    Broom
};

struct sVehicle
{
    std::string nameVehicle;
    tVehicle typeVehicle;
    tRace typeRace;
};

static std::vector<sVehicle> g_availableVehicles = {
    {"Верблюд",             tVehicle::Camel,            tRace::GROUND},
    {"Верблюд-быстроход",   tVehicle::SpeedCamel,       tRace::GROUND},
    {"Кентавр",             tVehicle::Centaur,          tRace::GROUND},
    {"Ботинки-вездеходы",   tVehicle::AllTerrainBoots,  tRace::GROUND},
    {"Орёл",                tVehicle::Eagle,            tRace::AERIAL},
    {"Ковёр-самолёт",       tVehicle::MagicCarpet,      tRace::AERIAL},
    {"Метла",               tVehicle::Broom,            tRace::AERIAL}
};