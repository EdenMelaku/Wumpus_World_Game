project(IntelligentAgent-components)

add_library(Inference_lib STATIC Inference.cpp Inference.h)
target_include_directories(Inference_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


