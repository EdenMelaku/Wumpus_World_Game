#project(IntelligentAgent-components)

add_library(Actuator_lib STATIC Actuator.cpp Actuator.h)
target_link_libraries(Actuator_lib KnowledgeBase_lib)
target_include_directories(Actuator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


