list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)

add_executable(logic_test logic_test.cpp)
target_link_libraries(logic_test PRIVATE Catch2::Catch2WithMain)

add_test(NAME logic_test COMMAND logic_test)
