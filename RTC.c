/*
* Desc:
* Author: Prangon Das (pcd3897@g.rit.edu)
*/
#include "MKL46Z4.h"
#include "RTC.h"

uint32_t seconds = 0;
uint32_t alarm = 0;

void init_RTC(uint8_t interrupt) {
	SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

	interrupt ? (NVIC->IP[RTC_IPR_REGISTER] |= NVIC_IPR_RTC_ALARM_MASK) : (NVIC->IP[RTC_IPR_REGISTER] |=
			NVIC_IPR_RTC_SEC_MASK);

	interrupt ? (NVIC->ICPR[0] |= NVIC_ICPR_RTC_ALARM_MASK) : (NVIC->ICPR[0] |=
			NVIC_ICPR_RTC_SEC_MASK);
	interrupt ? (NVIC->ISER[0] |= NVIC_ISER_RTC_ALARM_MASK) : (NVIC->ISER[0] |=
			NVIC_ISER_RTC_SEC_MASK);

	interrupt ? (RTC->IER |= RTC_IER_TAIE_MASK) : (RTC->IER |=
			RTC->IER |= RTC_IER_TSIE_MASK);

	RTC->CR = RTC_CR_CLK_OSC_WK;
}

void RTC_alarmSet(uint32_t time){
	RTC->TAR = time;
}

void RTC_start(){
	RTC->SR |= RTC_SR_TCE_MASK;
}

void RTC_reset(){
	RTC->CR |= RTC_CR_SWR_MASK;
	RTC->CR &= ~RTC_CR_SWR_MASK;
	seconds = 0;
	alarm = 0;
}

void RTC_IRQHandler(){
	__asm("CPSID I");
	alarm++;
	RTC->TAR |= RTC->TAR;
	__asm("CPSIE I");
}


void RTC_Seconds_IRQHandler(){
	__asm("CPSID I");
	seconds++;
	__asm("CPSIE I");
}
