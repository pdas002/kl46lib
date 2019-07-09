/*
 * Desc:
 * Author: Prangon Das (pcd3897@g.rit.edu)
 */

#include "MKL46Z4.h"
#include "GPIO.h"
#include "string.h"

/* PORTPins is expected to be like ["a3", "d5", "e29"].  */
uint8_t init_GPIO(uint8_t **PORTPins, uint8_t numPins) {
	for (uint8_t i = 0; i < numPins; i++) {
		uint8_t PORT = PORTPins[i][0];
		uint8_t pin = "";
		strcat(pin, PORTPins[i] + 1);
		if (strtol(pin, NULL, 10) > 32) {
			return 0;
		}
		switch (PORT) {
		case 'a':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTA_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
			}
			PORTA->PCR[strtol(pin, NULL, 10)] = PORT_PCR_GPIO_MASK;
			break;
		case 'b':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTB_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
			}
			PORTB->PCR[strtol(pin, NULL, 10)] = PORT_PCR_GPIO_MASK;
			break;
		case 'c':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTC_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
			}
			PORTC->PCR[strtol(pin, NULL, 10)] = PORT_PCR_GPIO_MASK;
			break;
		case 'd':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTD_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
			}
			PORTD->PCR[strtol(pin, NULL, 10)] = PORT_PCR_GPIO_MASK;
			break;
		case 'e':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTE_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
			}
			PORTE->PCR[strtol(pin, NULL, 10)] = PORT_PCR_GPIO_MASK;
			break;

		}

	}
	return 1;
}
