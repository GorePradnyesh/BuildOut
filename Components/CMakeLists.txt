cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC CONFIGURE_DEPENDS src/*.cpp src/*.c)
file(GLOB API CONFIGURE_DEPENDS API/*.h API/*.hpp)

add_library(Components ${SRC} ${API})

target_include_directories(Components PUBLIC API)

source_group(Src FILES ${SRC})
source_group(API FILES ${API})