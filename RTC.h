/*
 * RTC.h
 *
 *  Created on: Jul 11, 2019
 *      Author: Prangon Das
 */

#ifndef RTC_H_
#define RTC_H_

#define RTC_ALARM_NVIC_IRQ		(20)
#define RTC_SEC_NVIC_IRQ		(21)

#define NVIC_ICPR_RTC_ALARM_MASK 	(1 << RTC_ALARM_NVIC_IRQ)
#define NVIC_ICPR_RTC_SEC_MASK 		(1 << RTC_SEC_NVIC_IRQ)

#define NVIC_ISER_RTC_ALARM_MASK 	(1 << RTC_ALARM_NVIC_IRQ)
#define NVIC_ISER_RTC_SEC_MASK 		(1 << RTC_SEC_NVIC_IRQ)

#define RTC_IPR_REGISTER 		(5)

#define RTC_IER_TAIE_O_MASK		(1u << RTC_IER_TAIE_SHIFT)
#define RTC_IER_TSIE_O_MASK		(1u << RTC_IER_TSIE_SHIFT)

#define NVIC_IPR_RTC_ALARM_MASK		(3 << (((RTC_ALARM_NVIC_IRQ & 3) << 3) + 6))
#define NVIC_IPR_RTC_SEC_MASK 		(3 << (((RTC_SEC_NVIC_IRQ & 3) << 3) + 6))

#define RTC_CR_CLK_OSC_WK 		(RTC_CR_CLKO_MASK | RTC_CR_OSCE_MASK | RTC_CR_WPE_MASK)

void RTC_start(void);
void RTC_alarmSet(uint32_t time);
void init_RTC_IRQ(uint8_t interrupt);
uint32_t RTC_getSeconds(void);
uint32_t RTC_getAlarm(void);
void RTC_reset(void);

#endif /* RTC_H_ */
