#project(IntelligentAgent-components)

add_library(Sensor_lib STATIC Sensor.cpp Sensor.h)
target_link_libraries(Sensor_lib KnowledgeBase_lib)
target_include_directories(Sensor_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


