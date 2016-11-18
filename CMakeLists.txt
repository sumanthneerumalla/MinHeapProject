cmake_minimum_required(VERSION 3.6)
project(proj4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES PinHit.cpp PinHit.h Driver.cpp Heap.cpp Heap.h MinHeap.cpp MinHeap.h MaxHeap.cpp MaxHeap.h)
add_executable(proj4 ${SOURCE_FILES} MinHeap.cpp MinHeap.h MaxHeap.cpp MaxHeap.h)