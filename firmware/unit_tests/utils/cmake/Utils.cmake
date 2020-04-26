# ******************************************************************************
# Executes Python function
# retval Result of function execution
# ******************************************************************************
function(run_python_function function_name RET_VALUE)
	execute_process(
		COMMAND python -c
       "import sys; \
        sys.path.append('${CMAKE_CURRENT_LIST_DIR}/utils/cmake'); \
        from script import *; \
        ${function_name}()"
	    OUTPUT_VARIABLE RET_VALUE_TMP)
	string(REGEX REPLACE "\n$" "" RET_VALUE_TMP "${RET_VALUE_TMP}")
	set(${RET_VALUE} ${RET_VALUE_TMP} PARENT_SCOPE)
endfunction()

# ******************************************************************************
# Searches the gcovr progarm
# ******************************************************************************
function(find_gcovr)
	run_python_function(get_gcovr_version GCOVR_VERSION)
	if (GCOVR_VERSION STREQUAL "?")
		message(FATAL_ERROR "No gcovr installed")
	else()	
		message(STATUS "Found gcovr: version ${GCOVR_VERSION}")            
	endif()
endfunction()
