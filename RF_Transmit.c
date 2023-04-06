
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

const uint8_t DELAY_LEN = 50; //minimum is 10

int main(void)
{
DDRB |= _BV(DDB5);
DDRD |= _BV(DDD5);
DDRD &= ~_BV(DDD6);

while(1){
//checks if motion detector was tripped
if((PIND & (1 << PD6)) != 0){
//checking if it was just noise
_delay_ms(500);
if((PIND & (1 << PD6)) != 0){
//Starts signal output of HIGH-HIGH-LOW-LOW-HIGH-LOW-HIGH-HIGH

//HIGH
PORTD |= _BV(PORTD5);
PORTB |= _BV(PORTB5);
_delay_ms(DELAY_LEN);
//HIGH
PORTD |= _BV(PORTD5);
PORTB |= _BV(PORTB5);
_delay_ms(DELAY_LEN);
//LOW
PORTD &= ~_BV(PORTD5);
PORTB &= ~_BV(PORTB5);
_delay_ms(DELAY_LEN);
//LOW
PORTD &= ~_BV(PORTD5);
PORTB &= ~_BV(PORTB5);
_delay_ms(DELAY_LEN);
//HIGH
PORTD |= _BV(PORTD5);
PORTB |= _BV(PORTB5);
_delay_ms(DELAY_LEN);
//LOW
PORTD &= ~_BV(PORTD5);
PORTB &= ~_BV(PORTB5);
_delay_ms(DELAY_LEN);
//HIGH
PORTD |= _BV(PORTD5);
PORTB |= _BV(PORTB5);
_delay_ms(DELAY_LEN);
//HIGH
PORTD |= _BV(PORTD5);
PORTB |= _BV(PORTB5);
_delay_ms(DELAY_LEN);

//Reset
PORTD &= ~_BV(PORTD5);
PORTB &= ~_BV(PORTB5);





}
}
}
}