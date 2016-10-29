#ifndef CL_SPHERE_H
#define CL_SPHERE_H

#include <CL/cl.h>

extern "C" {
  cl_uint get_platforms_size();

  char * get_platform_name(cl_uint);
}

#endif
