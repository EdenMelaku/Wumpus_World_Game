project(IntelligentAgent-components)

add_library(Sensor_lib STATIC Sensor.cpp Sensor.h)
target_include_directories(Sensor_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


