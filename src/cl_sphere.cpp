#include "cl_sphere.h"
#include "cl_platform.hpp"
#include <cstring>

using std::string;
using std::vector;
using std::strcpy;

cl_uint get_platforms_size()
{
  return getPlatformsSize();
}

const char * get_platform_name(cl_uint position)
{
  auto platforms = getPlatforms();
  auto name = platforms[position].name;
  auto c_name = (char *) malloc(sizeof(char) * (name.size() + 1));

  strcpy(c_name, name.c_str());

  return c_name;
}
