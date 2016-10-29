#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#include <CL/cl.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct ClPlatform {
  string name;
};

cl_uint getPlatformsSize();
vector<ClPlatform> getPlatforms();

#endif
