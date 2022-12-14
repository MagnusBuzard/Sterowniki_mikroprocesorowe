


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

uint32_t i;

int main()
{
  DDRB |= (1 << PB2);

  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM13) | (1 << WGM12);

  TCCR1A |= (1 << COM1B1) | (1 << COM1B0);
  TCCR1B |= (1 << CS12);

  ICR1 = 1000;
  
  DDRC &= ~(1 << PC1);
  DDRC &= ~(1 << PC2);
  DDRC &= ~(1 << PC3);
  PCMSK1 |= (1 << PCINT11);
  PCMSK1 |= (1 << PCINT10);
  PCMSK1 |= (1 << PCINT9);
  PCICR |= (1 << PCIE1);
  EICRA |= (1 << ISC11);
  EICRA &= ~(1 << ISC10);
  sei();
  while (1)
  {
    
  }
}
ISR(PCINT1_vect)
{
  while(bit_is_clear(PINC, PC3))
  {
    if (i >= 1000)
    {
      i = 1000;
    }
    else
    {
      i += 1;
      OCR1B = i;
      _delay_ms(2);
    }
  }
  while(bit_is_clear(PINC, PC1))
  {
    if (i <= 0)
    {
      i = 0;
    }
    else
    {
      i -= 1;
      OCR1B = i;
      _delay_ms(2);
    }
  }
}
