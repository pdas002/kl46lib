/*
* Desc: U4ses interrupts to handle UART0 comms, needs KL46 to be configred to handle interrupts/
* Author: Prangon Das (pcd3897@g.rit.edu)
*/

#include "MKL46Z4.h"
#include "TxRxQueues.h"

#define UART_BUFF_SIZE (80)

char RxQBuffer [UART_BUFF_SIZE], TxQBuffer [UART_BUFF_SIZE];
struct qRecord RxQueue, TxQueue;

void init_UART0_IRQ(){
	init_Queue(RxQueue, RxQBuffer, UART_BUFF_SIZE);
	init_Queue(TxQueue, TxQBuffer, UART_BUFF_SIZE);

	/*TODO: Initialization. */
}
