cmake_minimum_required(VERSION 3.0.0)
project(stl-vector-wrapper VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(stl-vector-wrapper main.cpp container.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
