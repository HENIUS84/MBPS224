cmake_minimum_required(VERSION 3.16)

set(SOLUTION_NAME "MBPS224")
project("${SOLUTION_NAME}")
set(C_LIB_BY_HENIUS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/common)
include(${C_LIB_BY_HENIUS_DIR}/cmake/Utils.cmake)

# ******************************************************************************
# Builds the specified project
# ******************************************************************************
function(build_project PROJ_NAME PROJ_SUB_DIR)
	set(PROJ_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_SUB_DIR})
	message("**********************************************************")
	message("Compiling ${PROJ_NAME} project for ${SOLUTION_NAME}")
	message("**********************************************************")
	execute_process(COMMAND ${CMAKE_COMMAND}
					-G "Unix Makefiles"
					-DC_LIB_BY_HENIUS_DIR=${C_LIB_BY_HENIUS_DIR}
					-DSOLUTION_NAME=${SOLUTION_NAME}
					-B build
					${PROJ_PATH}/CMakeLists.txt)
	add_custom_target(${PROJ_NAME} ALL make -C ${PROJ_PATH})
endfunction()

################################
# Projects list
################################

# Building of MainBoard project
build_project(MainBoard main_board)

# Building of Unit Tests for MainBoard project
build_project(MainBoard_tests main_board/tests)

# Building of Unit Tests for Common project
build_project(CLibByHenius_tests common/tests)
