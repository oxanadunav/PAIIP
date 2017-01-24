#include "button.h"

///Makes first 4 pins of PORTC as Input
void initButtonOne() {
	DDRC &= ~(1 << PORTC0);
}

void initButtonTwo() {
	DDRC &= ~(1 << PORTC1) ;
}

void initButtonThree() {
	DDRC &= ~(1 << PORTC2) ;
}
void initButtonFour() {
	DDRC &= ~(1 << PORTC3) ;
}

void initButtonReset(){
	DDRC &= ~(1 << PORTC4) ;
}

int isButtonOnePressed() {
	return PINC & (1<<PORTC0);
}

int isButtonTwoPressed() {
	return PINC & (1<<PORTC1);
}

int isButtonThreePressed() {
	return PINC & (1<<PORTC2);
}
int isButtonFourPressed() {
	return PINC & (1<<PORTC3);
}

int isButtonResetPressed() {
	return PINC & (1<<PORTC4);
}