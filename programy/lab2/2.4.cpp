#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_1 PB5   //Nazwij Pin
#define LED_2 PB4   //Nazwij Pin
#define LED_3 PB3   //Nazwij Pin
#define S_1 PC1     //Nazwij Pin
#define S_2 PC2     //Nazwij Pin
#define S_3 PC3     //Nazwij Pin

ISR(PCINT1_vect)
{
  if(bit_is_clear(PINC,PC1)){
    PORTB ^= (1<<LED_1);
    _delay_ms(200);
  }
  if(bit_is_clear(PINC,PC2)){
    PORTB ^= (1<<LED_2);
    _delay_ms(200);
  }
  if(bit_is_clear(PINC,PC3)){
    PORTB ^= (1<<LED_3);
    _delay_ms(200);
  }

}
int main(void)
{
  DDRB |=(1<<LED_1);
  DDRB |=(1<<LED_2);
  DDRB |=(1<<LED_3);//Ustaw kierunek
  DDRC &= ~(1<<S_1);  //Ustaw kierunek
  PCMSK1  |= (1<<PCINT9);
  PCMSK1  |= (1<<PCINT10);
  PCMSK1  |= (1<<PCINT11);
  PCICR |= (1<<PCIE1);

  PORTB |= (1<<LED_1);
  PORTB |= (1<<LED_2);
  PORTB |= (1<<LED_3);
  sei();
  
 while(1){
 }  
}
