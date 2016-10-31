#include "cl_device.hpp"

string getDeviceName(const cl_device_id device_id) {
  size_t size;
  clGetDeviceInfo(device_id, CL_DEVICE_NAME, 0, NULL, &size);

  auto c_name = new char[size];
  clGetDeviceInfo(device_id, CL_DEVICE_NAME, size, (void *) c_name, NULL);

  auto name = string(c_name);

  delete[] c_name;

  return name;
}

cl_uint getDevicesSize(const cl_platform_id platform_id) {
  cl_uint size;
  clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, 0, NULL, &size);

  return size;
}

vector<ClDevice> getDevices(const cl_platform_id platform_id) {
  auto size = getDevicesSize(platform_id);

  auto cl_devices_id = new cl_device_id[size];

  clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ALL, size, cl_devices_id, NULL);

  vector<ClDevice> devices;
  for(decltype(size) i = 0; i != size; ++i) {
    auto device = getDevice(cl_devices_id[i]);
    devices.push_back(device);
  }

  delete[] cl_devices_id;

  return devices;
}

ClDevice getDevice(const cl_device_id device_id) {
  ClDevice device;
  device.id = device_id;
  device.name = getDeviceName(device_id);

  return device;
}
