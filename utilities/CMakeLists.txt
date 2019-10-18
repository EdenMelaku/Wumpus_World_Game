#project(IntelligentAgent-utilities)

add_library(Utility_lib STATIC Model.cpp Model.h)
target_include_directories(Utility_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})