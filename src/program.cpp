#include <cl_sphere.h>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  auto platforms = getNumberPlatforms();
  cout << "Listing " << platforms << " platforms..." << endl;

  for(decltype(platforms) i = 0; i != platforms; i++)
  {
    char *name = getPlatformName(i);
    cout << name << endl;
    free(name);
  }

  return 0;
}
