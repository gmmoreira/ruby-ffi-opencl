require 'ffi'
require 'pry'

module ClSphere
  extend FFI::Library
  ffi_lib 'build/libcl_sphere.so'

  typedef :pointer, :cl_platform_id
  typedef :uint32, :cl_uint

  attach_function :platforms_size, :get_platforms_size, [], :cl_uint
  attach_function :platform, :get_platform, [:cl_uint], :cl_platform_id
  attach_function :platform_name, :get_platform_name, [:cl_platform_id], :string
  attach_function :devices_size, :get_devices_size, [:cl_platform_id], :cl_uint
end

platforms_size = ClSphere.platforms_size

puts "Listing #{platforms_size} platforms..."

(0...platforms_size).each do |i|
  id = ClSphere.platform(i)
  name = ClSphere.platform_name(id)
  puts name

  puts "Devices: #{ClSphere.devices_size(id)}"
end


# Pointer#free
# :strptr = ["abc", ptr]
