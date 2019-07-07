/*
* Desc:
* Author: Prangon Das (pcd3897@g.rit.edu)
*/

#include "MKL46Z4.h"
#include "PIT.h"

int timer = 0;

void PIT_setStrtVal(int periodms){
	switch (periodms) {
	case 100:
		PIT->CHANNEL[0].LDVAL = PIT_PERIOD_100ms;
		break;
	case 1000:
		PIT->CHANNEL[0].LDVAL = PIT_PERIOD_1000ms;
		break;
	case 10000:
		PIT->CHANNEL[0].LDVAL = PIT_PERIOD_10000ms;
		break;
	}
}

void PIT_restart(){
	PIT->CHANNEL[0].TCTRL = PIT_TCTRL_TIMER_DISABLE;
	timer = 0;
	PIT->CHANNEL[0].TCTRL = PIT_TCTRL_TIMER_I_EN;
}

void PIT_IRQHandler(){
	__asm("CPSID I");
	if(PIT->CHANNEL[0].TFLG & PIT_TFLG_TIF_MASK){
		timer++;
		/* Writing one to it clears interrupt for next one */
		PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
	}
	__asm("CPSIE I");
}

int PIT_readTime(){
	return timer;
}

void PIT_start(){
	/* Enable PIT interrupt for channel/timer 0 and start timer*/
	PIT->CHANNEL[0].TCTRL = PIT_TCTRL_TIMER_I_EN;
}

void init_PIT_IRQ(int periodms){

	/* Enable clock for PIT */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

	/* Set PIT interrupt priority */
	NVIC->IP[PIT_NVIC_IPR_REGISTER] |= NVIC_IPR_PIT_MASK;
	/* Clear any pending PIT interrupts */
	NVIC->ICPR[0] = NVIC_ICPR_PIT_MASK;
	/* Unmask PIT interrupts */
	NVIC->ISER[0] = NVIC_ISER_PIT_MASK;

	/* Initialize timer value */
	PIT_setStrtVal(periodms);
	/* Enable PIT module with freeze during debugging */
	PIT->MCR = PIT_MCR_MDIS_FRZ_EN_MASK;
}


