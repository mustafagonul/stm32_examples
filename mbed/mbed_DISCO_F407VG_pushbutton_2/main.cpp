#include <mbed.h>


DigitalOut led(LED3);
DigitalIn userButton(USER_BUTTON);


int main()
{
  userButton.mode(PullDown);

  bool ledFlag = false;
  bool previousState = false;

  while (true) {
    led = ledFlag;

    bool currentState = userButton;
    if (currentState == true && previousState == false)
      ledFlag = !ledFlag;

    previousState = currentState;

    wait(0.01);
  }


  return 0;
}


