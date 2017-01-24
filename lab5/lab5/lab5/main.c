#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


// ********************************************************************************
// Interrupt Routines
// ********************************************************************************

uint32_t i = 0;

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect) {
    turn_off(0);
	turn_off(1);
	turn_off(2);
	toggle_led(i);
	i++;
	
	if(i > 2) {
		i = 0;
	}
}


int main( void ) {
    // Configure PORTA as output
    init_led();
	
    //Enable Overflow Interrupt Enable for Timer 0
    TIMSK= (1<<TOIE0);
    // set timer0 counter initial value to 0
    TCNT0=0x00;

    // Prescaler = FCPU/1024
    TCCR0 |= (1 << CS02) | (1 << CS00);
    // enable interrupts(set global interrupt flag)
    sei();
    while(1) {
	

    }
}