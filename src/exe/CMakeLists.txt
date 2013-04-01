file(GLOB exe_HEADERS "*.h")
file(GLOB exe_SOURCES "*.cpp")

add_executable(exe ${exe_SOURCES} ${exe_HEADERS})
if(WIN32)
else(WIN32)
	target_link_libraries(exe dl)
endif(WIN32)