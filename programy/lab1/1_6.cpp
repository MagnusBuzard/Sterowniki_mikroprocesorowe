#include <avr/io.h>
#include <util/delay.h>

#define LED_1 PB5
#define LED_2 PB4
#define LED_3 PB3
#define LED_4 PB2
#define S1 PC1


int main (void)
{
  int czas = 0;

  DDRB &= ~(1 << LED_1);
  DDRB &= ~(1 << LED_2);
  DDRB &= ~(1 << LED_3);
  DDRB &= ~(1 << LED_4);
  DDRC &= ~(1 << S1);
  while (1)
  {
    if (czas == 0)
    {
      DDRB &= ~(1 << LED_1);
      DDRB &= ~(1 << LED_2);
      DDRB &= ~(1 << LED_3);
      DDRB &= ~(1 << LED_4);
    }
    if (czas == 1)
    {
      DDRB |= (1 << LED_1);
      DDRB &= ~(1 << LED_2);
      DDRB &= ~(1 << LED_3);
      DDRB &= ~(1 << LED_4);
    }
    if (czas == 2)
    {
      DDRB |= (1 << LED_1);
      DDRB |= (1 << LED_2);
      DDRB &= ~(1 << LED_3);
      DDRB &= ~(1 << LED_4);
    }
    if (czas == 3)
    {
      DDRB |= (1 << LED_1);
      DDRB |= (1 << LED_2);
      DDRB |= (1 << LED_3);
      DDRB &= ~(1 << LED_4);
    }
    if (czas == 4)
    {
      DDRB |= (1 << LED_1);
      DDRB |= (1 << LED_2);
      DDRB |= (1 << LED_3);
      DDRB |= (1 << LED_4);
    }

    if (bit_is_clear(PINC, S1))
    {
      czas++;
    }
    if (bit_is_clear(PINC, S1) && czas >= 5)
    {
      czas = 0;
    }
    _delay_ms(200);
  }
}
