/*
 * Desc:
 * Author: Prangon Das (pcd3897@g.rit.edu)
 */

#include "MKL46Z4.h"
#include "GPIO.h"


/* PORTPins is expected to be like ["a3", "d5", "e29"].  */
uint8_t init_GPIO(struct SGPIO pininfo[], uint8_t numPins) {
	uint8_t i;
	for (i = 0; i < numPins; i++, pininfo++) {
		if (pininfo->pin > 32) {
			return 0;
		}
		switch (pininfo->PORT) {
		case 'a':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTA_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
			}
			PORTA->PCR[pininfo->pin] = PORT_PCR_GPIO_MASK;
			FPTA->PDDR |= (pininfo->dir << pininfo->pin);
			break;
		case 'b':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTB_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
			}
			PORTB->PCR[pininfo->pin] = PORT_PCR_GPIO_MASK;
			FPTB->PDDR |= (pininfo->dir << pininfo->pin);
			break;
		case 'c':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTC_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
			}
			PORTC->PCR[pininfo->pin] = PORT_PCR_GPIO_MASK;
			FPTC->PDDR |= (pininfo->dir << pininfo->pin);
			break;
		case 'd':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTD_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
			}
			PORTD->PCR[pininfo->pin] = PORT_PCR_GPIO_MASK;
			FPTD->PDDR |= (pininfo->dir << pininfo->pin);
			break;
		case 'e':
			if (!(SIM->SCGC5 & SIM_SCGC5_PORTE_MASK)) {
				SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
			}
			PORTE->PCR[pininfo->pin] = PORT_PCR_GPIO_MASK;
			FPTE->PDDR |= (pininfo->dir << pininfo->pin);
			break;
		default:
			return 0;
		}

	}
	return 1;
}

/* 1 good, 0 fail */
uint8_t GPIO_write(struct SGPIO *pininfo, uint8_t val) {
	uint8_t pin = pininfo->pin;
	if (val != 0 && val != 1) {
		return 0;
	} else {
		if (pin > 32) {
			return 0;
		} else {
			switch (pininfo->PORT) {
			case 'a':
				val ? (FPTA->PSOR |= (1u << pin)) : (FPTA->PCOR |=
							(1u << pin));
				break;
			case 'b':
				val ? (FPTA->PSOR |= (1u << pin)) : (FPTA->PCOR |=
							(1u << pin));
				break;
			case 'c':
				val ? (FPTA->PSOR |= (1u << pin)) : (FPTA->PCOR |=
							(1u << pin));
				break;
			case 'd':
				val ? (FPTA->PSOR |= (1u << pin)) : (FPTA->PCOR |=
							(1u << pin));
				break;
			case 'e':
				val ? (FPTA->PSOR |= (1u << pin)) : (FPTA->PCOR |=
							(1u << pin));
				break;
			default:
				return 0;
			}
		}
	}
	return 1;

}

/* 1/0 good, 2 fail */
uint8_t GPIO_read(struct SGPIO *pininfo) {
	uint8_t pin = pininfo->pin;
	if (pin > 32) {
		return 2;
	} else {
		switch (pininfo->PORT) {
		case 'a':
			return (FPTA->PDIR & (1u << pin)) ? 1 : 0;
		case 'b':
			return (FPTB->PDIR & (1u << pin)) ? 1 : 0;
		case 'c':
			return (FPTC->PDIR & (1u << pin)) ? 1 : 0;
		case 'd':
			return (FPTD->PDIR & (1u << pin)) ? 1 : 0;
		case 'e':
			return (FPTE->PDIR & (1u << pin)) ? 1 : 0;
		default:
			return 2;
		}
	}
}
