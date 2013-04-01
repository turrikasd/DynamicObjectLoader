file(GLOB exe_HEADERS "*.h")
file(GLOB exe_SOURCES "*.cpp")

add_executable(exe ${exe_SOURCES} ${exe_HEADERS})
target_link_libraries(exe dl slb)
