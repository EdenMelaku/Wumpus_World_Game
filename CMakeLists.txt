cmake_minimum_required (VERSION 3.10)
project (IntelligentAgent-WumpusWorld)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")

add_subdirectory(Game)
add_subdirectory(IntelligentAgent)

set(ww ma.cpp)
add_executable(wumpusworld ${ww})
find_package(Curses)

target_link_libraries(wumpusworld Game_lib iaww ${CURSES_LIBRARIES})
