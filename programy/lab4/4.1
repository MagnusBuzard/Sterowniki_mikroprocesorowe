#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint32_t i = 1000;

int main(){
  DDRB |= (1<< PB2);

  TCCR1A |=(1<<WGM11);
  TCCR1B |=(1<<WGM13) | (1<<WGM12);

  TCCR1A |=(1<<COM1B1) | (1<<COM1B0);
  TCCR1B |=(1<<CS12);

  ICR1 = 1000;
  while(1)
  {
    for (i=0;i<1000;i++)
    {
      OCR1B = i;
      _delay_ms(1);
    }
    for (i=1000; i>0; i--)
    {
      OCR1B=i;
      _delay_ms(1);
    }
  }
}
