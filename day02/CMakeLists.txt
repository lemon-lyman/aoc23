# Add executable 1
add_executable(day02 day02.cpp)

# Link libraries
target_link_libraries(day02 common_lib)
target_include_directories(day02 PRIVATE ../)
