#include "cl_platform.hpp"

using std::string;
using std::vector;
using std::begin;
using std::end;

cl_uint getPlatformsSize()
{
  cl_uint platforms_size;
  clGetPlatformIDs(0, NULL, &platforms_size);

  return platforms_size;
}

vector<ClPlatform> getPlatforms() {
  vector<ClPlatform> platforms;
  auto platforms_size = getPlatformsSize();

  auto platforms_id = new cl_platform_id[platforms_size];

  clGetPlatformIDs(platforms_size, platforms_id, NULL);

  for(decltype(platforms_size) i = 0; i != platforms_size; ++i) {
    size_t size;
    clGetPlatformInfo(platforms_id[i], CL_PLATFORM_NAME, 0, NULL, &size);

    auto name = new char[size];

    clGetPlatformInfo(platforms_id[i], CL_PLATFORM_NAME, size, (void *) name, NULL);
    ClPlatform platform;
    platform.name = string(name);
    platforms.push_back(platform);

    delete[] name;
  }

  delete[] platforms_id;

  return platforms;
}

