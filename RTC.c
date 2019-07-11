/*
* Desc:
* Author: Prangon Das (pcd3897@g.rit.edu)
*/
#include "MKL46Z4.h"
#include "RTC.h"

void init_RTC(uint8_t interrupt) {
	SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

	interrupt ? (NVIC->IP[RTC_IPR_REGISTER] |= NVIC_IPR_RTC_ALARM_MASK) : (NVIC->IP[RTC_IPR_REGISTER] |=
					NVIC_IPR_RTC_SEC_MASK);

	interrupt ? (NVIC->ICPR[0] |= NVIC_ICPR_RTC_ALARM_MASK) : (NVIC->ICPR[0] |=
					NVIC_ICPR_RTC_SEC_MASK);
	interrupt ? (NVIC->ISER[0] |= NVIC_ISER_RTC_ALARM_MASK) : (NVIC->ISER[0] |=
					NVIC_ISER_RTC_SEC_MASK);

	RTC->CR = RTC_CR_CLK_OSC_WK;
}

void RTC_alarmSet(){


}

void RTC_start(){

}


void RTC_IRQHandler(){


}


void RTC_Seconds_IRQHandler(){


}
