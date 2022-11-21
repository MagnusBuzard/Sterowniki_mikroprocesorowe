//---------------------------------------
//wartość_przeładowania w 3.1 i 3.2
//---------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define WARTOSC_PRZELADOWANIA 35415
#define LED_13 PB5
#define LED_12 PB4
#define BTN1_PIN PC1

ISR(TIMER1_OVF_vect)
{
  TCNT1 = WARTOSC_PRZELADOWANIA;
  PORTB ^= (1 << LED_12);
}

ISR(PCINT1_vect)
{
  if(bit_is_clear(PINC,PC1))
  {

  }
  else
  {
  PORTB^= (1<<LED_13);
  }
}

int main (void)
{
  TCCR1B &=~ (1<<WGM13);
  TCCR1B &=~ (1<<WGM12);
  TCCR1B &=~ (1<<WGM11);
  TCCR1B &=~ (1<<WGM10);
  DDRB |= (1<<LED_13);
  DDRB |= (1<<LED_12);
  DDRC &=~ (1<<BTN1_PIN);
  TCCR1B &=~ (1<< CS10);
  TCCR1B &=~ (1<< CS11);
  TCCR1B |= (1<<CS12);
  TIMSK1 |=(1<<TOIE1);
  TCNT1 = WARTOSC_PRZELADOWANIA;
  PCMSK1 |=(1<<PCINT9);
  PCICR |=(1<<PCIE1);
  sei();

  while(1)
  {
     
  }
  
}
