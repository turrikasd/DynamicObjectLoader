cmake_minimum_required (VERSION 2.6)
project (DynamicObjectLoader)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories("${PROJECT_SOURCE_DIR}/src/exe")
include_directories("${PROJECT_SOURCE_DIR}/src/slb")

add_subdirectory(src/exe)
add_subdirectory(src/slb)
