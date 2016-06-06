/*
 * uart.c
 *
 * Created: 2016/6/6 15:28:41
 * Author : wkxbo
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "uart.h"

int main(void)
{
	uint8_t cnt;
	
	sei();
	uart_init(UART_BAUD_SELECT(9600,8000000UL));
	uart_puts_P("\r\nhello wkxboot!");
	uart_puts_P("\r\nwait for data...");
	
	
    /* Replace with your application code */
    while (1) 
    {
		cnt=uart_available();
		if (cnt)
		{
		while (cnt)
		{
			uart_puts_P("\r\nrecv data:");
			uart_putc((uint8_t)uart_getc());
			cnt--;
		}
			
		}
    }
}

