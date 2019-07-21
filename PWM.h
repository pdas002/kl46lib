/*
 * PWM.h
 *      Author: Prangon Das
 */

#ifndef PWM_H_
#define PWM_H_

#define PTE31_TPM0_CH4_O_MASK (PORT_PCR_ISF_MASK | (3 << PORT_PCR_MUX_SHIFT)

#define SIM_SOPT2_TPMSRC_MCGPLLCLK (1u << SIM_SOPT2_TPMSRC_SHIFT)

#define SIM_SOPT2_TPM_MCGPLLCLK_DIV2  (SIM_SOPT2_TPMSRC_MCGPLLCLK | SIM_SOPT2_PLLFLLSEL_MASK)

#define TPM_SC_PS_16_MASK (1u << 2)

#define TPM_MSB_ELSB_10 ((1u << 5) | (1u << 3))


#endif /* PWM_H_ */
