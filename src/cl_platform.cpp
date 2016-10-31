#include "cl_platform.hpp"

using std::string;
using std::vector;

cl_uint getPlatformsSize()
{
  cl_uint platforms_size;
  clGetPlatformIDs(0, NULL, &platforms_size);

  return platforms_size;
}

ClPlatform getPlatform(const cl_platform_id platform_id) {
    ClPlatform platform;
    platform.id =         platform_id;
    platform.profile =    getPlatformInfo(platform_id, CL_PLATFORM_PROFILE);
    platform.version =    getPlatformInfo(platform_id, CL_PLATFORM_VERSION);
    platform.name =       getPlatformInfo(platform_id, CL_PLATFORM_NAME);
    platform.vendor =     getPlatformInfo(platform_id, CL_PLATFORM_VENDOR);
    platform.extensions = getPlatformInfo(platform_id, CL_PLATFORM_EXTENSIONS);

    return platform;
}

vector<ClPlatform> getPlatforms() {
  auto platforms_size = getPlatformsSize();

  auto platforms_id = new cl_platform_id[platforms_size];

  clGetPlatformIDs(platforms_size, platforms_id, NULL);

  vector<ClPlatform> platforms;
  for(decltype(platforms_size) i = 0; i != platforms_size; ++i) {
    ClPlatform platform = getPlatform(platforms_id[i]);
    platforms.push_back(platform);
  }

  delete[] platforms_id;

  return platforms;
}

string getPlatformInfo(const cl_platform_id platform_id, const cl_platform_info platform_info) {
  size_t size;
  clGetPlatformInfo(platform_id, platform_info, 0, NULL, &size);
  auto c_data = new char[size];
  clGetPlatformInfo(platform_id, platform_info, size, (void *) c_data, NULL);

  auto data = string(c_data);

  delete[] c_data;

  return data;
}
