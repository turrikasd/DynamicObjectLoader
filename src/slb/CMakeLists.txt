file(GLOB slb_HEADERS "*.h")
file(GLOB slb_SOURCES "*.cpp")

add_library(slb SHARED ${slb_SOURCES} ${slb_HEADERS})
