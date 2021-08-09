cmake_minimum_required(VERSION 3.0.0)
project(MinesweeperUI VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MinesweeperUI Main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
include(Tests/CMakeTests.txt)