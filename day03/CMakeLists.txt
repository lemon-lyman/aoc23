# Add executable 1
add_executable(day03 day03.cpp)

# Link libraries
target_link_libraries(day03 common_lib)
target_include_directories(day03 PRIVATE ../)
