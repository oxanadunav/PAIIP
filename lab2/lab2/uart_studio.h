#ifndef UART_STUDIO_H_
#define UART_STUDIO_H_

#define F_CPU 1000000UL
#include <stdio.h>
#include <avr/io.h>
	
	void uart_stdio_Init(void);
	int uart_stdio_PutChar(char c, FILE *stream);

#endif /* UART_STUDIO_H_ */