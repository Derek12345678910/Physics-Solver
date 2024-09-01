cmake_minimum_required(VERSION 3.13)
project(Physics-Solver)

set(CMAKE_CXX_STANDARD 17)

# Add all files
file(GLOB SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Add the executable
add_executable(run.exe ${SOURCE_FILES})

# Link libraries
target_link_libraries(run.exe)