
add_library(IntelligentAgent_lib STATIC IA.cpp AI.h)
target_link_libraries(IntelligentAgent KnowledgeBase_lib Sensor_lib Inference_lib Actuator_lib)
target_include_directories(IntelligentAgent PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


