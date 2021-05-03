cmake_minimum_required(VERSION 3.20)

set(SRC
        main.cpp)
set(Inc
        CommonIncludes.h)        

set(CMAKE_CXX_STANDARD 17)

add_executable(BuildOut ${SRC} ${Inc})

source_group(Src FILES ${SRC})
source_group(Inc FILES ${Inc})

target_link_libraries(BuildOut Components)