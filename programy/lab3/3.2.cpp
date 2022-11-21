#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define WARTOSC_PRZELADOWANIA 30120

ISR(TIMER1_COMPA_vect)
{
  PORTB ^= (1 << PB5);
}

int main (void)
{
  TCCR1B |= (1<<WGM12) | (1 << CS11) | (1 << CS10);
  TCCR1B &=~ (1<<CS12);
  TCNT1 = 0;
  OCR1A = WARTOSC_PRZELADOWANIA;
  TIMSK1 |= (1<<OCIE1A);
  sei();
  DDRB |= (1<<PB5);

  while(1)
  {
     
  }
  
}
//----------------------------------------------------------
//reloadValue - wartość przeładowania
//reloadValue = (fclk)/(N*f)
//fclk 16*10^6
//𝑁 = 1, 8, 64, 256, 1024
//----------------------------------------------------------
