project(IntelligentAgent-Utilities)

add_library(Utilities_lib STATIC DataStructures.h)
target_include_directories(Utilities_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


