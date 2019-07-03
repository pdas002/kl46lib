#ifndef UART_0
#define UART_0

#define NVIC_ICPR_UART0_MASK (1 << 12)

#define NVIC_ISER_UART0_MASK (1 << 12)

#define UART0_IPR_REGISTER (12 >> 2)

#define NVIC_IPR_UART0_MASK \
                      (3 << (((12 & 3) << 3) + 6))

#define PORT_PCR_SET_PTA_UART0_TR (PORT_PCR_ISF_MASK | \
                                    (2u << PORT_PCR_MUX_SHIFT))

#define SIM_SOPT2_UART0_MCGPLLCLK_DIV2 \
       ((1u << SIM_SOPT2_UART0SRC_SHIFT) | SIM_SOPT2_PLLFLLSEL_MASK)

#define SIM_SOPT5_UART0_EXTERN_MASK_CLEAR  \
                                  (SIM_SOPT5_UART0ODE_MASK | \
                                   SIM_SOPT5_UART0RXSRC_MASK | \
                                   SIM_SOPT5_UART0TXSRC_MASK)

#define UART0_BDH_9600  (0x01u)

#define UART0_BDL_9600  (0x38u)

#define UART0_C1_8N1  (0x00)

#define UART0_C2_T_R    (UART0_C2_TE_MASK | UART0_C2_RE_MASK)
#define UART0_C2_T_RI   (UART0_C2_T_R | UART0_C2_RIE_MASK)
#define UART0_C2_TI_RI  (UART0_C2_T_RI | UART0_C2_TIE_MASK)

#define UART0_C3_NO_TXINV  (0x00)

#define UART0_C4_NO_MATCH_OSR_16  (0x0Fu)

#define UART0_C5_NO_DMA_SSR_SYNC  (0x00)

#define UART0_S1_CLEAR_FLAGS  (0x1Fu)

#define UART0_S2_NO_RXINV_BRK10_NO_LBKDETECT_CLEAR_FLAGS  (0xC0u)

void init_UART0_IRQ(void);
char getChar(void);
void putChar(const char character);

#endif
