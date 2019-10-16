cmake_minimum_required (VERSION 3.10)
project (IntelligentAgent-WumpusWorld)

# set(CMAKE_CXX_STANDARD 14)

# add_subdirectory(utilities)
add_subdirectory(components/KnowledgeBase)
add_subdirectory(components/Sensor)
add_subdirectory(components/Inference)
add_subdirectory(components/Actuator)
add_subdirectory(agent/IntelligentAgent)

set(iagent main.cpp)
add_executable(wwia ${iagent})

target_link_libraries(wwia IntelligentAgent_lib)

