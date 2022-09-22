project(task4_2)

cmake_minimum_required (VERSION 3.8)

add_library (unionFind STATIC Union-find.cpp)

add_executable(main TrueWay.cpp)

target_link_libraries(main unionFind)