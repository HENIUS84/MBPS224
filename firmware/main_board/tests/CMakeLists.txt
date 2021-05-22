cmake_minimum_required(VERSION 3.16)

include(FetchContent)
set(FETCHCONTENT_QUIET off)

################################
# Paths
################################

# cmake libs directory resolving
set (CMAKE_LIB_DIR "${C_LIB_BY_HENIUS_DIR}/cmake")
include(${CMAKE_LIB_DIR}/Utils.cmake)

# Firmware directory resolving
get_filename_component(FIRMWARE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

# Tested source files directory resolving
set(TESTED_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

################################
# Project settings
################################

set(PROJECT_NAME "MainBoard_Tests")
project(${PROJECT_NAME})

include(${CMAKE_LIB_DIR}/UnitTests-toolchain.cmake)

################################
# Tests
################################
include_directories(
    mocks
	${C_LIB_BY_HENIUS_DIR}/include
	${C_LIB_BY_HENIUS_DIR}/include/gtest
	${C_LIB_BY_HENIUS_DIR}/source/utils
	${C_LIB_BY_HENIUS_DIR}/include/utils
	${C_LIB_BY_HENIUS_DIR}/source/avr/drivers
	${C_LIB_BY_HENIUS_DIR}/include/avr/drivers
	${googletest_SOURCE_DIR}/googlemock/include)
	
file (GLOB_RECURSE TEST_SRC_FILES REC
      ${PROJECT_SOURCE_DIR}/tests/*.cpp
      ${PROJECT_SOURCE_DIR}/mocks/*.cpp)
configure_unit_tests()