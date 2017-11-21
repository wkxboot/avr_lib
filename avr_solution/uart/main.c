/*
 * uart.c
 *
 * Created: 2016/6/6 15:28:41
 * Author : wkxboot
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
	uart_puts_P("hello wkxboot!\r\n");
	uart_puts_P("wait for data...\r\n");
	
	
    /* Replace with your application code */
    while (1) 
    {
		cnt=uart_available();
		if (cnt)
		{
		while (cnt)
		{
			uart_puts_P("recv data:");
			uart_putc((uint8_t)uart_getc());
			cnt--;
		}
			
		}
    }
}

