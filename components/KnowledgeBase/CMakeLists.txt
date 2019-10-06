#project(IntelligentAgent-components)

add_library(KnowledgeBase_lib STATIC KB.cpp KB.h)
target_include_directories(KnowledgeBase_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


