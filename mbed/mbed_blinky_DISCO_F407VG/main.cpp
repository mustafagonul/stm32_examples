#include <mbed.h>


int main()
{
  DigitalOut myled(LED3);

  while(1) {
    myled = 1;
    wait(0.2);

    myled = 0;
    wait(0.2);
  }

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


