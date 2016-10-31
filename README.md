# ruby-ffi-opencl
Simple ruby script interacting with a C lib using OpenCL.

## Motivations
With this project, I expect:

 - learn more about C and C++
 - learn more about OpenCL and parallel programming
 - learn how to use Ruby FFI

By any means the code is optimized and may have a lot of mistakes. The only purpose of this project is to learn and share what my progress so far.

## Dependencies
### OpenCL
This project depends on the AMD APP SDK 2.9.1. It can be downloaded from [here][amd-app-sdk].

### Ruby
This project has been developed on Ruby 2.3.1. It should run fine on previous versions.

It also depends on the `ffi` gem.

### C
The C project depends on `cmake` to build it. The code also makes use of c++11 functionality, so you must have a compatible compiler.

## Building
To build the C lib, just run in your terminal:

`./build.sh`

Inside build directory you will find `program` executable and `libcl_sphere.so` shared library.

## Running
After building the C project, you can:

 - run a C executable by tiping `build/program`
 - run a ruby script by tiping `ruby ruby_ffi.rb`

[amd-app-sdk]: http://developer.amd.com/tools-and-sdks/opencl-zone/amd-accelerated-parallel-processing-app-sdk/
