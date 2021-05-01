cmake_minimum_required(VERSION 3.20)

set(SRC
        main.cpp)

add_executable(BuildOut ${SRC})

source_group(Src FILES ${SRC})

target_link_libraries(BuildOut Components)