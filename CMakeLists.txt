cmake_minimum_required(VERSION 3.31.6)

# Keep the original flags style; just enable CUDA so nvcc builds the .cu.
project(PixelManipulator LANGUAGES CXX CUDA)

# Match your original flags; applies to both host and device.
add_compile_options(-O3 -std=c++14)
set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

add_executable(PixelBatch greenScreenProcess.cpp greenScreen.cu image.cpp)
