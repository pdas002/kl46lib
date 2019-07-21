/*
* Desc:
* Author: Prangon Das (pcd3897@g.rit.edu)
*/
#include "MKL46Z4.h"
#include "PWM.h"

void init_PWM(){
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;

	PORTE->PCR[31] |= PTE31_TPM0_CH4_O_MASK;

	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPM_MCGPLLCLK_DIV2;

	TPM0 ->SC |= TPM_SC_PS_16_MASK;

	TPM0->CONTROLS->CnSC |= TPM_MSB_ELSB_10;

}

void PWM_setDutyCycle(uint16_t dutyCycle){
	TPM0->CONTROLS->CnV = dutyCycle;
}
