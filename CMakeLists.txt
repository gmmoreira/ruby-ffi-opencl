cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(opencl)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIB_NAME "cl_sphere")
set(EXE_NAME "program")
set(TEST_NAME "program_test")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest)

# Find OpenCL include and libs
find_path( OPENCL_INCLUDE_DIRS
  NAMES OpenCL/cl.h CL/cl.h
  HINTS $ENV{AMDAPPSDKROOT}/include/
  )

find_library( OPENCL_LIBRARIES
  NAMES OpenCL
  HINTS $ENV{AMDAPPSDKROOT}/lib
  PATH_SUFFIXES x86_64
  )

# Find Google Test include and libs
#find_path(GOOGLE_TEST_INCLUDE_DIRS
#  NAMES gtest/gtest.h
#  HINTS $ENV{GOOGLETESTROOT}/googletest/include/
#  )
#
#find_library(GOOGLE_TEST_LIB
#  NAMES gtest gmock
#  HINTS ${CMAKE_CURRENT_SOURCE_DIR}/lib
#  )

include_directories(${OPENCL_INCLUDE_DIRS})
include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${LIB_NAME} SHARED "src/cl_sphere.cpp" "src/cl_platform.cpp" "src/cl_device.cpp")
target_link_libraries(${LIB_NAME} ${OPENCL_LIBRARIES})

add_executable(${EXE_NAME} "src/program.cpp")
target_link_libraries(${EXE_NAME} ${LIB_NAME})

add_executable(${TEST_NAME} "test/main.cpp")
target_link_libraries(${TEST_NAME} ${LIB_NAME} gtest gmock pthread)
