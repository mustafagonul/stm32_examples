#include <mbed.h>


int main()
{
  DigitalOut step(PC_0);
  DigitalOut direction(PC_1);
  DigitalOut led(LED3);
  DigitalIn userButton(USER_BUTTON);


  while (true) {
    direction = userButton;
    led = userButton;

    step = true;
    wait_ms(10);
    step = false;
    wait_ms(10);
  }

  return 0;
}




