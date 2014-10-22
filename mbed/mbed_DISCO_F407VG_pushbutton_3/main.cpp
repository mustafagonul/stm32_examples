#include <mbed.h>


DigitalOut led(LED3);
InterruptIn buttonInterrupt(USER_BUTTON);
bool ledSwitch = false;


void ledOnOff()
{
  ledSwitch = !ledSwitch;
}


int main()
{
  buttonInterrupt.rise(ledOnOff);


  while (true)
    led = ledSwitch;

  return 0;
}
