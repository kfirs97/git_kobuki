cmake_minimum_required(VERSION 3.16)
project(gpu_ws)

set(CMAKE_CXX_STANDARD 14)

add_executable(gpu_ws main.cpp)

# find packages we want to use
find_package(OpenCV 4 REQUIRED)

# find_package(CUDA REQUIRED)
include_directories(
        ${OpenCV_INCLUDE_DIRS}
#         ${CUDA_INCLUDE_DIRS}
)

# linking the project with the libraries
target_link_libraries(
        gpu_ws ${OpenCV_LIBS}
#        gpu_project ${CUDA_LIBRARIES}
        )