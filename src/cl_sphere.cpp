#include "cl_sphere.h"

cl_uint get_platforms_size()
{
  cl_uint platforms_size;
  clGetPlatformIDs(0, NULL, &platforms_size);

  return platforms_size;
}

char * get_platform_name(cl_uint position)
{
  auto platforms_size = get_platforms_size();

  cl_platform_id *platforms_id;
  platforms_id = (cl_platform_id *) malloc(sizeof(&platforms_id) * platforms_size);

  clGetPlatformIDs(1, platforms_id, NULL);

  size_t size;

  clGetPlatformInfo(platforms_id[position], CL_PLATFORM_NAME, 0, NULL, &size);

  char *name;
  name = (char *) malloc(sizeof(&name) * size);

  clGetPlatformInfo(platforms_id[position], CL_PLATFORM_NAME, size, (void *) name, NULL);

  return name;
}
