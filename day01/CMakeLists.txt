# Add executable 1
add_executable(day01 day01.cpp)

# Link libraries
target_link_libraries(day01 common_lib)
target_include_directories(day01 PRIVATE ../)
