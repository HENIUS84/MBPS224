cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME "UnitTests")
project(${PROJECT_NAME})
enable_testing()
set(PYTHON_EXECUTABLE ${PYTHON3})

# Firmware directory resolving
get_filename_component(FIRMWARE_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

# Common directory resolving
set (COMMON_DIR "${FIRMWARE_DIR}/Common")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
     -g \
    -DGTEST_OS_CYGWIN=1 \
    -DGTEST_USE_OWN_TR1_TUPLE=1 \
    -DGTEST_HAS_TR1_TUPLE=1 \
    -std=gnu++14 \
    -Wno-narrowing")

################################
# GTest
################################
include(FetchContent)
set(FETCHCONTENT_QUIET off)
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
	${COMMON_DIR}/include
	${COMMON_DIR}/source)
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "Include dir='${dir}'")
endforeach()	
	
file (GLOB TEST_SRC_FILES
	  # Test file
      ${PROJECT_SOURCE_DIR}/tests/common/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main)
