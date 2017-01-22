#include "adc.h"
#include <avr/io.h>
int data;

void initADC() {
	// AREF = AVcc Reference Selection Bits – These bits are used to choose the reference voltage
	ADMUX = (1 << REFS0);
	// ADC Enable and prescaler of 128 (16000000/128 = 125000)
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int getData() {

	int adcData = 0;
	int port = 3;
	
	// wait for conversion to complete
	// ADSC becomes ’0? again, till then, run loop continuously
	while(ADCSRA & 1 << ADSC);
	
	// select the corresponding channel 0~7
    // ANDing with ’7? will always keep the value between 0 and 7
	port &= 0x07; 
	
	ADMUX = (ADMUX & ~(0x07)) | port; //clears the bits
	ADCSRA |= (1<<ADSC); // start single convertion write ’1? to ADSC
	while (ADCSRA & (1<<ADSC));
	adcData = ADC;
	return adcData;

}