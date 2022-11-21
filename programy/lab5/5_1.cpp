#include "HD44780.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() 
{
  LCD_Initalize();
  char buf[64];
  uint8_t i;
  while (1) 
  {

    LCD_Home();
    LCD_WriteText("Wololo");
    LCD_GoTo(0, 1);
    LCD_WriteText("15.11.2022 15:00");
    _delay_ms(1000);
    LCD_Clear();

  }
}
