#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>

void initButtonOne();
void initButtonTwo();
void initButtonThree();
void initButtonFour();
void initButtonReset();

int isButtonOnePressed();
int isButtonTwoPressed();
int isButtonThreePressed();
int isButtonFourPressed();
int isButtonResetPressed();

#endif /* BUTTON_H_ */