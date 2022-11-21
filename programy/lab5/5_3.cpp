#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#include <stdio.h>
#include <avr/interrupt.h>

#define button PC0

//inicjalizacja ADC
void initADC() 
{
  ADCSRA |= (1 << ADEN); //włącz ADC
  ADMUX |= (1 << REFS0); //wew źródło odniesienia
  ADCSRA |= (1 << ADATE) | (1 << ADPS0) | (1 << ADPS1); //preskaler 128
  sei();
}

int main() 
{
  initADC();
  LCD_Initalize(); //inicjacja LCD

  char buf[64]; //definicja bufora na znaki wyswietlacza

  while (1) 
  {
    uint64_t adc = ADC;//odczyt ADC por A0

    uint64_t napiecie = (adc * (5.0 / 1023)) * 1000;//przeliczenie ADC na napiecie w [mV]
    char button;

    LCD_Home();//ustawienie kursora LCD w pozycji 0,0

    if (adc == 1022) //sprawdzanie jaki przycisk jest wcisniety (sa połączone szeregowo przez coraz większe rezystory(mniejszy prąd mniejsza wartość ADC))
    {
      button = 'n';
    }
    if (adc == 134) 
    {
      button = 'u';
    } 
    if (adc == 480) 
    {
      button = 'l';
    } 
    if (adc == 719) 
    {
      button = 's';
    } 
    if (adc == 0) 
    {
      button = 'r';
    }  
    if (adc == 307) 
    {
      button = 'd';
    }

    sprintf(buf, "Nap:%d [mV] ", napiecie); //Wyświetlanie napiecia
    LCD_WriteText(buf);

    LCD_GoTo(0, 1);//przestawienie kursora do drugiej linijki

    sprintf(buf, "Przycisk: %c ", button); //wyswietlanie przycisku
    LCD_WriteText(buf);
    ADCSRA |= (1 << ADSC);
    _delay_ms(100);
  }
}
