file(GLOB TEST_SOURCE_FILES *.cpp *.hpp *.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_ARCHIVE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_LIBRARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_RUNTIME_OUTPUT_DIR})

include_directories(${COMMON_ALGORITHM_SOURCE_DIR})
link_directories(${COMMON_ALGORITHM_LIBRARY_OUTPUT_DIR})

add_executable(CommonAlgorithm.Test ${TEST_SOURCE_FILES})
target_link_libraries(CommonAlgorithm.Test 
	CommonAlgorithm)

set_target_properties(CommonAlgorithm.Test PROPERTIES COMPILE_FLAGS "/MTd")
set_target_properties(CommonAlgorithm.Test PROPERTIES SUFFIX ".exe")
set_target_properties(CommonAlgorithm.Test PROPERTIES FOLDER "Algorithm Targets")
