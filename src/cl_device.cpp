#include "cl_device.hpp"

cl_uint getDevicesSize(cl_platform_id platform_id) {
  cl_uint size;
  clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 0, NULL, &size);

  return size;
}
