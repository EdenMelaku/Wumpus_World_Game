
add_library(IntelligentAgent_lib STATIC IA.cpp IA.h)
target_link_libraries(IntelligentAgent_lib KnowledgeBase_lib Sensor_lib Inference_lib Actuator_lib)
target_include_directories(IntelligentAgent_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


