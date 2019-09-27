project(IntelligentAgent-WumpusWorld_tests)

add_executable(tests testmain.cpp)
target_link_libraries(prog PRIVATE KnowlegeBase_lib)
