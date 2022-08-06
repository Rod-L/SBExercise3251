cmake_minimum_required(VERSION 3.22)
project(SBExercise3251)

set(CMAKE_CXX_STANDARD 14)

add_executable(SBExercise3251 main.cpp StrExtra.h)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.1/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(SBExercise3251 PRIVATE nlohmann_json::nlohmann_json)
