#project(IntelligentAgent-components)

add_library(Inference_lib STATIC Inference.cpp Inference.h)
target_link_libraries(Inference_lib Utility_lib KnowledgeBase_lib)
target_include_directories(Inference_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


