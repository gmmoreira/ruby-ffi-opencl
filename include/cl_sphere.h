#ifndef CL_SPHERE_H
#define CL_SPHERE_H

#include <CL/cl.h>

extern "C" {
  cl_uint get_platforms_size();

  cl_platform_id get_platform(cl_uint);

  const char * get_platform_name(cl_platform_id);

  cl_uint get_devices_size(cl_platform_id);

  cl_device_id get_device(cl_platform_id, cl_uint);

  const char * get_device_name(cl_device_id);
}

#endif
