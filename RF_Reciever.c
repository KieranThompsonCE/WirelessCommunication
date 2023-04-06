
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

const uint8_t DELAY_LEN = 50; //minimum is 10
const uint16_t ALARM_TIME = 5000; //time is in ms
int main(void)
{
DDRB |= _BV(DDB5);
DDRD &= ~_BV(DDD6);
DDRD |= _BV(DDD3);
DDRD |= _BV(DDD2);
while(1){
//checking for initial input from received signal
if((PIND & (1 << PD6)) != 0){
PORTB |= _BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) != 0){
//checking for proper sequence HIGH-HIGH-LOW-LOW-HIGH-LOW-HIGH-HIGH
//It delays by DELAY_LEN before reading the signal
//First reading has already been checked
_delay_ms(DELAY_LEN);

//HIGH
if((PIND & (1 << PD6)) != 0){
PORTB |= _BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) != 0){
_delay_ms(DELAY_LEN);


//LOW
if((PIND & (1 << PD6)) == 0){
PORTB &= ~_BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) == 0){
_delay_ms(DELAY_LEN);


//LOW
if((PIND & (1 << PD6)) == 0){
PORTB &= ~_BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) == 0){
_delay_ms(DELAY_LEN);


//HIGH
if((PIND & (1 << PD6)) != 0){
PORTB |= _BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) != 0){
_delay_ms(DELAY_LEN);


//LOW
if((PIND & (1 << PD6)) == 0){
PORTB &= ~_BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) == 0){
_delay_ms(DELAY_LEN);


//HIGH
if((PIND & (1 << PD6)) != 0){
PORTB |= _BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) != 0){
_delay_ms(DELAY_LEN);

//HIGH
if((PIND & (1 << PD6)) != 0){
PORTB |= _BV(PORTB5);
//checking if it was just noise
_delay_ms(1);
if((PIND & (1 << PD6)) != 0){


//Signal Complete turn on buzzer and LED for 5 seconds
PORTD |= _BV(PD2);
uint16_t cur_time = 0;
while(cur_time <= ALARM_TIME){
PORTD |= _BV(PD3);
_delay_ms(1);
PORTD &= ~(_BV(PD3));
_delay_ms(1);
cur_time += 2;
}
PORTD &= ~(_BV(PD3));
PORTD &= ~(_BV(PD2));
}}}}}}}}}}}}}}}}
}
}