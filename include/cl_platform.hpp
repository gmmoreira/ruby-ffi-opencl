#ifndef CL_PLATFORM_H
#define CL_PLATFORM_H

#include <CL/cl.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct ClPlatform {
  cl_platform_id id;
  string profile;
  string version;
  string name;
  string vendor;
  string extensions;
};

cl_uint getPlatformsSize();
ClPlatform getPlatform(const cl_platform_id);
vector<ClPlatform> getPlatforms();
string getPlatformInfo(const cl_platform_id, const cl_platform_info);

#endif
