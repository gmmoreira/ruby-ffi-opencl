#ifndef _CL_SPHERE_H
#define _CL_SPHERE_H

#include <CL/cl.h>

extern "C" {
  cl_uint getNumberPlatforms();

  char * getPlatformName(cl_uint);
}

#endif
