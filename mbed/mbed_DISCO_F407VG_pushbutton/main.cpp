#include <mbed.h>


DigitalOut led(LED3);
DigitalIn userButton(USER_BUTTON);


int main()
{
  userButton.mode(PullDown);

  while(true)
    led = userButton;

  return 0;
}




