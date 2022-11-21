#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define WARTOSC_PRZELADOWANIA 35415

ISR(TIMER1_OVF_vect)
{
  TCNT1 = WARTOSC_PRZELADOWANIA;
  PORTB ^= (1 << PB5);
}

int main (void)
{
  TCCR1B &=~ (1<<WGM13);
  TCCR1B &=~ (1<<WGM12);
  TCCR1B &=~ (1<<WGM11);
  TCCR1B &=~ (1<<WGM10);
  DDRB |= (1<<PB5);
  TCCR1B |= (1<< CS10);
  TCCR1B |= (1<< CS11);
  TCCR1B &=~ (1<<CS12);
  TIMSK1 |=(1<<TOIE1);
  TCNT1 = WARTOSC_PRZELADOWANIA;
  sei();

  while(1)
  {
     
  }
  
}
//----------------------------------------------------------
//reloadValue - wartość przeładowania
//reloadValue = 2^ (liczba bitów timera) - (fclk)/(N*f)
//fclk 16*10^6
//liczba bitów timera najczęściej 16 (brać 16 i chuj)
//𝑁 = 1, 8, 64, 256, 1024
//----------------------------------------------------------
