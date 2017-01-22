#include "led.h"

void initLed() {
	DDRD |= (1 << PORTD6);
}

void ledOn() {
	PORTD |= (1 << PORTD6);
}

void ledOff() {
	PORTD &= ~(1 << PORTD6);
}