cmake_minimum_required (VERSION 3.10)
project (IntelligentAgent-WumpusWorld)

# set(CMAKE_CXX_STANDARD 14)

add_subdirectory(utilities)
add_subdirectory(components/KnowledgeBase)
add_subdirectory(components/Sensor)
add_subdirectory(components/Inference)
add_subdirectory(components/Actuator)
add_subdirectory(IntelligentAgent)

add_library(iaww INTERFACE)
target_link_libraries(iaww INTERFACE IntelligentAgent_lib)
