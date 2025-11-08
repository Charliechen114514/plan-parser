cmake_minimum_required(VERSION 3.25.0)
project(plan_parser VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_BUILD_TYPE "Debug")
file(GLOB_RECURSE PlanParserSrc
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(PlanParser ${PlanParserSrc})
target_include_directories(PlanParser PUBLIC plan_parser utils)

add_subdirectory(example)