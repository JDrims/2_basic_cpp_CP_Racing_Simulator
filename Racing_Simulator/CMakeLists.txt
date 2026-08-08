cmake_minimum_required (VERSION 3.10)

project ("Racing_Simulator" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (Racing_Simulator
"main.cpp"
"header/GameManager.h"
"source/GameManager.cpp"
 "header/RaceAPI.h")

target_link_libraries(Racing_Simulator PRIVATE DLL)

target_include_directories("Racing_Simulator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
target_include_directories("Racing_Simulator" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)
target_include_directories("Racing_Simulator" PRIVATE ${CMAKE_SOURCE_DIR}/DLL)

add_custom_command(TARGET Racing_Simulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:DLL>
        $<TARGET_FILE_DIR:Racing_Simulator>
    COMMENT "Копирование DLL.dll в папку приложения"
)