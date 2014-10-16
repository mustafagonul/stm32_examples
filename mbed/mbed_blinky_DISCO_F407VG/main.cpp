#include <mbed.h>


DigitalOut myled(LED3);


int main()
{
  while (true) {
    myled = 1;
    wait(0.2);

    myled = 0;
    wait(0.2);
  }

  return 0;
}


