#include <cl_sphere.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  auto platforms = get_platforms_size();
  cout << "Listing " << platforms << " platforms..." << endl;

  for(decltype(platforms) i = 0; i != platforms; i++)
  {
    auto platform_id = get_platform(i);

    auto platform_name = get_platform_name(platform_id);
    cout << platform_name << endl;

    auto devices_size = get_devices_size(platform_id);

    cout << "Listing devices..." << endl;
    for(decltype(devices_size) d = 0; d != devices_size; ++d) {
      auto device_id = get_device(platform_id, d);

      auto device_name = get_device_name(device_id);

      cout << device_name << endl;
    }

  }

  return 0;
}
