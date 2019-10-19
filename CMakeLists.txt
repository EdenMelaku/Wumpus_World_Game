cmake_minimum_required (VERSION 3.10)
project (IntelligentAgent-WumpusWorld)

 set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Game)
#add_subdirectory(ModelBasedAgent)
set(ww ma.cpp)
add_executable(wumpusworld ${ww})
target_link_libraries(client ncurses)

target_link_libraries(wumpusworld Game_lib)

