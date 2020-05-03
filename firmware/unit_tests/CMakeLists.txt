cmake_minimum_required(VERSION 3.17)

include(FetchContent)
set(FETCHCONTENT_QUIET off)

################################
# Paths
################################

# Firmware directory resolving
get_filename_component(FIRMWARE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

# Utils directory resolving
set (UTILS_DIR "${C_LIB_BY_HENIUS_DIR}/cmake")
include(${UTILS_DIR}/Utils.cmake)

################################
# Project settings
################################

set(PROJECT_NAME "UnitTests")
project(${PROJECT_NAME})
enable_testing()
add_compile_definitions(I2C_DEBUG_ENABLED)

################################
# Test coverage tool
################################

find_coverage_tool()

################################
# Compiler settings
################################

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -g \
    -DGTEST_USE_OWN_TR1_TUPLE=1 \
    -DGTEST_HAS_TR1_TUPLE=1 \
    -std=gnu++14 \
    -coverage -fprofile-arcs -ftest-coverage")

################################
# GTest
################################

option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)
option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  message(STATUS "Fetching Google Test...")
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

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
add_executable(${PROJECT_NAME}
               main.cpp
               ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC gmock gmock_main)

################################
# POST Build
################################

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   -DSOLUTION_NAME=${SOLUTION_NAME}
                   -DPROJECT_NAME=${PROJECT_NAME}
                   -DPROJECT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}
                   -DFIRMWARE_DIR=${FIRMWARE_DIR}
                   -DUTILS_DIR=${UTILS_DIR}
                   -P ${CMAKE_CURRENT_SOURCE_DIR}/POST.cmake)
