#include <avr/io.h>
#include <avr/interrupt.h>

int main()
{
  DDRB |= (1 << PB2);

  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM13) | (1 << WGM12);

  TCCR1A |= (1 << COM1B1) | (1 << COM1B0);
  TCCR1B |= (1 << CS12);

  ICR1 = 625; //(16*10^6)/(100*256) --> (fclk)/(f*N)
  OCR1B = 31; // wypelnienie * ICR1 --> 0.05*625
  while (1)
  {
    
  }
}
