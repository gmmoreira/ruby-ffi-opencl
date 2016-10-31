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
    auto id = get_platform(i);

    auto name = get_platform_name(id);
    cout << name << endl;

    auto devices_size = get_devices_size(id);

    cout << "Devices: " << devices_size << endl;
  }

  return 0;
}
