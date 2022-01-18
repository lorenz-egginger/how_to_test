list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)

add_executable(behavior_test behavior_test.cpp)
target_link_libraries(behavior_test PRIVATE Catch2::Catch2WithMain)

add_test(NAME behavior_test COMMAND behavior_test)
