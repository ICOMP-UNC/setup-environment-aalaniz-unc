cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "tp0_SO2_2024"
    VERSION 1.0.0
    DESCRIPTION "First project of SO2 2024"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})