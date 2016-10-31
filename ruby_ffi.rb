require 'ffi'
require 'pry'

module ClSphere
  extend FFI::Library
  ffi_lib 'build/libcl_sphere.so'

  attach_function :platforms_size, :get_platforms_size, [], :uint32
  attach_function :platform, :get_platform, [:uint32], :pointer
  attach_function :platform_name, :get_platform_name, [:pointer], :strptr
  attach_function :devices_size, :get_devices_size, [:pointer], :uint32
end

platforms_size = ClSphere.platforms_size

puts "Listing #{platforms_size} platforms..."

(0...platforms_size).each do |i|
  id = ClSphere.platform(i)
  name, ptr = ClSphere.platform_name(id)
  puts name

  puts "Devices: #{ClSphere.devices_size(id)}"
end


# Pointer#free
# :strptr = ["abc", ptr]
