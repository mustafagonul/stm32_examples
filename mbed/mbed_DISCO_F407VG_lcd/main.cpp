#include <mbed.h>
#include "TextLCD.h"


TextLCD lcd(PA_0, PA_1, PA_2, PA_3, PA_4, PA_5); // rs, e, d4-d7


int main()
{
  lcd.printf("Hello World!\n");

  while(true)
    ;

  return 0;
}
