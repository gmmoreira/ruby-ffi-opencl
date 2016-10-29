cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(opencl)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIB_NAME "cl_sphere")
set(EXE_NAME "program")

# Find OpenCL include and libs
find_path( OPENCL_INCLUDE_DIRS
  NAMES OpenCL/cl.h CL/cl.h
  HINTS ../../../../include/ $ENV{AMDAPPSDKROOT}/include/
  )

find_library( OPENCL_LIBRARIES
  NAMES OpenCL
  HINTS ../../../../lib/ $ENV{AMDAPPSDKROOT}/lib
  PATH_SUFFIXES x86_64
  )

include_directories(${OPENCL_INCLUDE_DIRS})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(${LIB_NAME} SHARED "src/cl_sphere.cpp" "src/cl_platform.cpp")
target_link_libraries(${LIB_NAME} ${OPENCL_LIBRARIES})

add_executable(${EXE_NAME} "src/program.cpp")
target_link_libraries(${EXE_NAME} ${LIB_NAME})
