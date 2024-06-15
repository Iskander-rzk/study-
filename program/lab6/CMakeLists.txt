cmake_minimum_required(VERSION 3.0.0)
project(study+ VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(main prog_lab6_1.cpp prog_lab6_2.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
