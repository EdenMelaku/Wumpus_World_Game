
add_library(Game_lib STATIC Room.h Room.cpp World.h World.cpp playableWorld.h playableWorld.cpp sensor.h sensor.cpp actions.h actions.cpp playGround.h playGround.cpp)
# target_link_libraries(Game_lib )
target_include_directories(Game_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
