cmake_minimum_required(VERSION 3.26)
project(sniffer)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 23)

add_executable(sniffer parser.cpp)

add_executable(snifferTest test.cpp)

target_link_libraries(snifferTest gtest gtest_main)

add_test(NAME snifferTest COMMAND snifferTest)
