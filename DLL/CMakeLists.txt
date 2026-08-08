cmake_minimum_required (VERSION 3.10)

project ("DLL" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DLL SHARED
 "header/Vehicle.h"
 "header/GroundVehicle.h"
 "source/GroundVehicle.cpp"
 "header/AirVehicle.h"
 "source/AirVehicle.cpp"
 "header/Camel.h"
 "source/Camel.cpp"
 "header/SpeedCamel.h"
 "source/SpeedCamel.cpp"
 "header/Centaur.h"
 "source/Centaur.cpp"
 "header/AllTerrainBoots.h"
 "source/AllTerrainBoots.cpp"
 "header/MagicCarpet.h"
 "source/MagicCarpet.cpp"
 "header/Eagle.h"
 "source/Eagle.cpp"
 "header/Broom.h"
 "source/Broom.cpp"
 "header/Race.h"
 "source/Race.cpp"
 "header/GroundRace.h"
 "source/GroundRace.cpp"
 "header/AirRace.h"
 "source/AirRace.cpp"
 "header/MixedRace.h"
 "source/MixedRace.cpp"
 "header/RaceAPI.h"
 "source/RaceAPI.cpp"
 "header/TypeDef.h")

target_include_directories(DLL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
target_include_directories(DLL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

target_compile_definitions(DLL PRIVATE RACE_LIBRARY_EXPORTS)