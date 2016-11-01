#include "button.h"

void initButton() {
	DDRC &= ~(1 << PORTC5) ;
}

int isPressed() {
	return PINC & (1<<PORTC5);
}
