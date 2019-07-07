/*
 * Desc: U4ses interrupts to handle UART0 comms, needs KL46 to be configred to handle interrupts/
 * Author: Prangon Das (pcd3897@g.rit.edu)
 */

#include "MKL46Z4.h"
#include "TxRxQueues.h"
#include "UART0.h"

#define UART_BUFF_SIZE (80)

char RxQBuffer[UART_BUFF_SIZE], TxQBuffer[UART_BUFF_SIZE];
struct qRecord RxQueue, TxQueue;

void init_UART0_IRQ() {
	init_Queue(&RxQueue, RxQBuffer, UART_BUFF_SIZE);
	init_Queue(&TxQueue, TxQBuffer, UART_BUFF_SIZE);

	/* Select MCGPLLCLK / 2 as UART0 clock source */
	SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_UART0_MCGPLLCLK_DIV2;
	/* Set UART0 for external connection */
	SIM->SOPT5 &= ~SIM_SOPT5_UART0_EXTERN_MASK_CLEAR;
	/* Enable UART0 module clock */
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
	/* Enable PORT A module clock */
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	/* Some OpenSDA applications provide a virtual serial port */
	/* through the OpenSDA USB connection using PTA1 and PTA2  */
	PORTA->PCR[1] = PORT_PCR_SET_PTA_UART0_TR;
	PORTA->PCR[2] = PORT_PCR_SET_PTA_UART0_TR;
	/* Disable UART0 */
	UART0->C2 &= ~UART0_C2_T_R;
	/* Set UART0 interrupt priority */
	NVIC->IP[UART0_IPR_REGISTER] |= NVIC_IPR_UART0_MASK;
	/* Clear any pending UART0 interrupts */
	NVIC->ICPR[0] = NVIC_ICPR_UART0_MASK;
	/* Unmask UART0 interrupts */
	NVIC->ISER[0] = NVIC_ISER_UART0_MASK;
	/* Set for 9600 baud from 96MHz PLL clock */
	UART0->BDH = UART0_BDH_9600;
	UART0->BDL = UART0_BDL_9600;
	UART0->C1 = UART0_C1_8N1;
	UART0->C3 = UART0_C3_NO_TXINV;
	UART0->C4 = UART0_C4_NO_MATCH_OSR_16;
	UART0->C5 = UART0_C5_NO_DMA_SSR_SYNC;
	UART0->S1 = UART0_S1_CLEAR_FLAGS;
	UART0->S2 = UART0_S2_NO_RXINV_BRK10_NO_LBKDETECT_CLEAR_FLAGS;
	UART0->C2 = UART0_C2_T_RI; /* enable UART0 */
}

void UART0_IRQHandler(){
	__asm("CPSID I");
	if(UART0->C2 & UART0_C2_TIE_MASK){
		if(UART0->S1 & UART0_S1_TDRE_MASK){
			if(!dequeue((char*)(&UART0->D), &TxQueue)){
				UART0->C2 = UART0_C2_T_RI;
			}
		}
	}
	if(UART0->S1 & UART0_S1_RDRF_MASK){
		enqueue(UART0->D, &RxQueue);
	}
	__asm("CPSIE I");
}

char getChar() {
	char character;
	int success;

	do {
		__asm("CPSID I");
		success = dequeue(&character, &RxQueue);
		__asm("CPSIE I");
	} while (!success);

	return character;
}

void putChar(const char character) {
	int success;

	do {
		__asm("CPSID I");
		success = enqueue(character, &TxQueue);
		__asm("CPSIE I");
	} while (!success);

	UART0->C2 = UART0_C2_TI_RI;
}
