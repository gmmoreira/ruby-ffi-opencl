#include "cl_sphere.h"
#include "cl_platform.hpp"
#include "cl_device.hpp"
#include <cstring>

using std::string;
using std::vector;
using std::strcpy;

cl_uint get_platforms_size() {
  return getPlatformsSize();
}

cl_platform_id get_platform(cl_uint position) {
  auto platforms = getPlatforms();

  return platforms[position].id;
}

const char * get_platform_name(cl_platform_id platform_id) {
  auto platform = getPlatform(platform_id);
  auto name = platform.name;
  auto c_name = (char *) malloc(sizeof(char) * (name.size() + 1));

  strcpy(c_name, name.c_str());

  return c_name;
}

cl_uint get_devices_size(cl_platform_id platform_id) {
  return getDevicesSize(platform_id);
}
