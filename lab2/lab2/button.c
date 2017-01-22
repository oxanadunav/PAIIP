#include "button.h"

void initButton() {
	DDRA &= ~(1 << PORTA3);
}

int isPressed() {
	return PINA & (1<<PORTA3);
}
