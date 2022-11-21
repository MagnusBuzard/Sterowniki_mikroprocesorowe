#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#include <stdio.h>
#include <avr/interrupt.h>

//inicjalizacja ADC
void initADC() 
  {
  ADCSRA |= (1 << ADEN);

  ADMUX |= (1 << REFS0);
  ADCSRA |= (1 << ADATE);
  ADCSRA |= (1 << ADPS0);
  ADCSRA |= (1 << ADPS1);
  sei();
  }

int main() 
{

  initADC(); 
  LCD_Initalize(); //inicjacja LCD

  char buf[64]; //definicja bufora na znaki wyswietlacza

  while (1) 
    {
    uint64_t adc = ADC; //odczyt ADC por A0
    uint64_t napiecie = (adc * (5.0 / 1023)) * 1000; //przeliczenie ADC na napiecie w [mV]
    
    LCD_Home(); //ustawienie kursora LCD w pozycji 0,0
    
    sprintf(buf, "ADC: %d ", adc);//Wyświetlanie adc
    LCD_WriteText(buf);

    LCD_GoTo(0, 1);//przestawienie kursora do drugiej linijki
    sprintf(buf, "Nap: %d [mV] ", napiecie);//wyswietlanie napiecia
    LCD_WriteText(buf);

    ADCSRA |= (1 << ADSC);
    _delay_ms(100);
    }
}
