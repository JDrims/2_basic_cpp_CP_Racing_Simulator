cmake_minimum_required (VERSION 3.10)

project ("DLL" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DLL SHARED
"main.cpp"
)

target_include_directories(DLL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)

target_compile_definitions(DLL PRIVATE LIB_EXPORTS)