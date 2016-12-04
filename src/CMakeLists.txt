file(GLOB SOURCE_FILES *.cpp *.h *.hpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_ARCHIVE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_LIBRARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${COMMON_ALGORITHM_RUNTIME_OUTPUT_DIR})

add_library(CommonAlgorithm STATIC 
	${SOURCE_FILES})

set_target_properties(CommonAlgorithm PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(CommonAlgorithm PROPERTIES COMPILE_FLAGS "/MTd")
set_target_properties(CommonAlgorithm PROPERTIES SUFFIX ".lib")
set_target_properties(CommonAlgorithm PROPERTIES FOLDER "Algorithm Targets")

