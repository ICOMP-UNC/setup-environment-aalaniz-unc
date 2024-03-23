cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "tp0_SO2_2024"
    VERSION 1.2.0
    DESCRIPTION "First project of SO2 2024"
    LANGUAGES C
)

include(CTest)

set(CMAKE_C_STANDARD 17)

include_directories(include)

include(FetchContent)
set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

FetchContent_MakeAvailable(Unity)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(lib/dynamic_lib)
add_subdirectory(lib/static_lib)

target_include_directories(${PROJECT_NAME} PUBLIC lib/dynamic_lib/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/static_lib/include)

target_link_libraries(${PROJECT_NAME} static_lib_tp0_SO2_2024 dynamic_lib_tp0_SO2_2024)

if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()
