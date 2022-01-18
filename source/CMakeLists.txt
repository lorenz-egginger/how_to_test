cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(how_to_test VERSION 0.1.0 LANGUAGES CXX)

# Unit Tests
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.4)
FetchContent_MakeAvailable(Catch2)

enable_testing()

add_subdirectory(behavior)
add_subdirectory(logic)
