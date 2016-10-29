require 'ffi'
require 'pry'

module ClSphere
  extend FFI::Library
  ffi_lib 'build/libcl_sphere.so'

  attach_function :number_platforms, 'getNumberPlatforms', [], :uint32
  attach_function :platform_name, 'getPlatformName', [:uint32], :strptr
end

platforms_size = ClSphere.number_platforms

puts platforms_size

(0...platforms_size).each do |i|
  name, ptr = ClSphere.platform_name(i)
  puts name
end


# Pointer#free
# :strptr = ["abc", ptr]
