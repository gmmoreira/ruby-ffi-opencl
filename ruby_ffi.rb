require 'ffi'
require 'pry'

module ClSphere
  extend FFI::Library
  ffi_lib 'build/libcl_sphere.so'

  typedef :pointer, :cl_platform_id
  typedef :pointer, :cl_device_id
  typedef :uint32, :cl_uint

  attach_function :platforms_size, :get_platforms_size, [], :cl_uint
  attach_function :platform, :get_platform, [:cl_uint], :cl_platform_id
  attach_function :platform_name, :get_platform_name, [:cl_platform_id], :string
  attach_function :devices_size, :get_devices_size, [:cl_platform_id], :cl_uint
  attach_function :device, :get_device, [:cl_platform_id, :cl_uint], :cl_device_id
  attach_function :device_name, :get_device_name, [:cl_device_id], :string
end

platforms_size = ClSphere.platforms_size

puts "Listing #{platforms_size} platforms..."

(0...platforms_size).each do |i|
  platform_id = ClSphere.platform(i)
  platform_name = ClSphere.platform_name(platform_id)
  puts platform_name

  devices_size = ClSphere.devices_size(platform_id)

  puts "Listing devices..."
  (0...devices_size).each do |d|
    device_id = ClSphere.device(platform_id, d)
    device_name = ClSphere.device_name(device_id)
    puts device_name
  end
end


# Pointer#free
# :strptr = ["abc", ptr]
