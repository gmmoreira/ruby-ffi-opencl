require 'ffi'
require 'pry'

module ClSphere
  extend FFI::Library
  ffi_lib 'build/libcl_sphere.so'

  attach_function :platforms_size, 'get_platforms_size', [], :uint32
  attach_function :platform_name, 'get_platform_name', [:uint32], :strptr
end

platforms_size = ClSphere.platforms_size

puts "Listing #{platforms_size} platforms..."

(0...platforms_size).each do |i|
  name, ptr = ClSphere.platform_name(i)
  puts name
end


# Pointer#free
# :strptr = ["abc", ptr]
