#include <CL/cl.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct ClDevice {
  cl_device_id id;
  string name;
};

cl_uint getDevicesSize(const cl_platform_id);
vector<ClDevice> getDevices(const cl_platform_id);
ClDevice getDevice(const cl_device_id);

