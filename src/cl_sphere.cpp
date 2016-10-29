#include "cl_sphere.h"

cl_uint getNumberPlatforms()
{
  cl_uint numPlatforms;
  clGetPlatformIDs(0, NULL, &numPlatforms);

  return numPlatforms;
}

char * getPlatformName(cl_uint position)
{
  auto platformsSize = getNumberPlatforms();

  auto platformId = (cl_platform_id *) malloc(sizeof(cl_platform_id) * platformsSize);

  clGetPlatformIDs(1, platformId, NULL);

  size_t size;

  clGetPlatformInfo(platformId[position], CL_PLATFORM_NAME, 0, NULL, &size);

  auto name = (char *) malloc(sizeof(char) * size);

  clGetPlatformInfo(platformId[position], CL_PLATFORM_NAME, size, (void *) name, NULL);

  return name;
}
