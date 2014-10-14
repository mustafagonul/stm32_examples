#include <mbed.h>


int main()
{
  return 0;
}


// Other functions that are necessary for building
extern "C" int __wrap_main();

extern "C" int _start()
{
  return __wrap_main();
}

extern "C" int __real_main()
{
  return main();
}




