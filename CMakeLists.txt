cmake_minimum_required (VERSION 3.10)
project (IntelligentAgent-WumpusWorld)

 set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")
add_subdirectory(Game)
add_subdirectory(ModelBasedAgent)
link_directories(ModelBasedAgent)
set(ww ma.cpp)
find_package(Curses)

add_executable(wumpusworld ${ww})
target_link_libraries(wumpusworld ${CURSES_LIBRARIES})

target_link_libraries(wumpusworld Game_lib)
target_link_libraries(wumpusworld iaww)

