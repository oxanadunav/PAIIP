#include <avr/io.h>
#include "button.h"
#include "lcd.h"
#include <avr/delay.h>

int main(void) {
	
	int aScore = 0;
	int bScore = 0; 
	int cScore = 0;
	int dScore = 0;
	initButtonOne();
	initButtonTwo();
	uart_stdio_Init();
	
	//Initialize LCD module
    LCDInit(LS_NONE);

    //Clear the screen
    LCDClear();
	LCDWriteStringXY(0,0,"A="); 
	LCDWriteStringXY(6,0,"B="); 
	LCDWriteStringXY(0,1,"C=");
	LCDWriteStringXY(6,1,"D=");

	LCDWriteIntXY(2,0,aScore,2);
	LCDWriteIntXY(8,0,bScore,2);
	LCDWriteIntXY(2,1,cScore,2);
	LCDWriteIntXY(8,1,dScore,2);
	
    while(1) {
		_delay_ms(10);
		
		if(!isButtonOnePressed()) {
			aScore++;
			LCDWriteIntXY(2,0,aScore,2);
	
		}
		if(!isButtonTwoPressed()) {
			bScore++;
			LCDWriteIntXY(8,0,bScore,2);	
		}
		if(!isButtonThreePressed()) {
			cScore++;
			LCDWriteIntXY(2,1,cScore,2);	
		}
		if(!isButtonFourPressed()) {
			dScore++;
			LCDWriteIntXY(8,1,dScore,2);	
		}
		if(!isButtonResetPressed()) {
			aScore = 0;
			bScore = 0;
			cScore = 0;
			dScore = 0;
			LCDWriteIntXY(2,0,aScore,2);
			LCDWriteIntXY(8,0,bScore,2);
			LCDWriteIntXY(2,1,cScore,2);
			LCDWriteIntXY(8,1,dScore,2);	
		}
	}	
    
}