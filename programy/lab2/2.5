#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_1 PB5   //Nazwij Pin
#define LED_2 PB4   //Nazwij Pin
#define LED_3 PB3   //Nazwij Pin
#define LED_4 PB2   //Nazwij Pin
#define S_1 PC1     //Nazwij Pin

int licznik = 0;

ISR(PCINT1_vect)
{
  if(bit_is_clear(PINC,PC1)){
    licznik++;
    _delay_ms(200);
    if(licznik >4){
      licznik=0;
    }
  }
}
int main(void)
{
  DDRB |=(1<<LED_1);
  DDRB |=(1<<LED_2);
  DDRB |=(1<<LED_3);//Ustaw kierunek
  DDRB |=(1<<LED_4);//Ustaw kierunek
  DDRC &= ~(1<<S_1);  //Ustaw kierunek
  PCMSK1  |= (1<<PCINT9);
  PCICR |= (1<<PCIE1);
  sei();  
 while(1){
  if(licznik == 4){
    PORTB &= ~(1<<LED_1);
    PORTB &= ~(1<<LED_2);
    PORTB &= ~(1<<LED_3);
    PORTB &= ~(1<<LED_4);
    _delay_ms(300);
  }
  if(licznik == 3){
    PORTB |= (1<<LED_1);
    PORTB &= ~(1<<LED_2);
    PORTB &= ~(1<<LED_3);
    PORTB &= ~(1<<LED_4);
    _delay_ms(300);
  }
  if(licznik == 2){
    PORTB |= (1<<LED_1);
    PORTB |= (1<<LED_2);
    PORTB &= ~(1<<LED_3);
    PORTB &= ~(1<<LED_4);
    _delay_ms(300);
  }
    if(licznik == 1){
    PORTB |= (1<<LED_1);
    PORTB |= (1<<LED_2);
    PORTB |= (1<<LED_3);
    PORTB &= ~(1<<LED_4);
    _delay_ms(300);
  }
    if(licznik == 0){
    PORTB |= (1<<LED_1);
    PORTB |= (1<<LED_2);
    PORTB |= (1<<LED_3);
    PORTB |= (1<<LED_4);
    _delay_ms(300);
  }
  
  }
 }
