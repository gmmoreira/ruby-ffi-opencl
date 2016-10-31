#include "cl_sphere.h"
#include "cl_platform.hpp"
#include "cl_device.hpp"
#include <cstring>

using std::string;
using std::vector;
using std::strcpy;

const char * string_to_char(string data) {
  auto c_data = (char *) malloc(sizeof(char) * (data.size() + 1));

  strcpy(c_data, data.c_str());

  return c_data;
}

cl_uint get_platforms_size() {
  return getPlatformsSize();
}

cl_platform_id get_platform(cl_uint position) {
  auto platforms = getPlatforms();

  return platforms[position].id;
}

const char * get_platform_name(cl_platform_id platform_id) {
  auto platform = getPlatform(platform_id);

  return string_to_char(platform.name);
}

cl_uint get_devices_size(cl_platform_id platform_id) {
  return getDevicesSize(platform_id);
}

cl_device_id get_device(cl_platform_id platform_id, cl_uint position) {
  auto devices = getDevices(platform_id);

  return devices[position].id;
}

const char * get_device_name(cl_device_id device_id) {
  auto device = getDevice(device_id);

  return string_to_char(device.name);
}
