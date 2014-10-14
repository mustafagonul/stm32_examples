#include <mbed.h>
#include "TextLCD.h"


int main()
{
  TextLCD lcd(PA_0, PA_1, PA_2, PA_3, PA_4, PA_5); // rs, e, d4-d7

  lcd.printf("Hello World!\n");

  while(true)
    ;

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


