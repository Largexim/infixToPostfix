cmake_minimum_required(VERSION 3.0)

project(List)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Add your executable
add_executable(List main.cpp List.cpp)

# Link SFML libraries to your executable
target_link_libraries(List sfml-graphics)