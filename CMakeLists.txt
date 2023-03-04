cmake_minimum_required(VERSION 3.22.0)

project(raceProject)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(transportLibrary SHARED
transport/Transport.h transport/Transport.cpp
transport/GroundTransport.h transport/GroundTransport.cpp
transport/AirTransport.h transport/AirTransport.cpp
transport/BootsAllTerrain.h transport/BootsAllTerrain.cpp
transport/Broom.h transport/Broom.cpp
transport/Camel.h transport/Camel.cpp
transport/CarpetPlane.h transport/CarpetPlane.cpp
transport/Centaur.h transport/Centaur.cpp
transport/Eagle.h transport/Eagle.cpp
transport/FastCamel.h transport/FastCamel.cpp)

add_executable(race main.cpp)

target_link_libraries(race transportLibrary)