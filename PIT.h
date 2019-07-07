#ifndef PI_T
#define PI_T


#define PIT_MCR_MDIS_FRZ_EN_MASK	(0x00);

#define PIT_TCTRL_TIMER_I_EN		(PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK)
#define PIT_TCTRL_TIMER_DISABLE		(0x00)

#define PIT_PERIOD_100ms		(0x253770)
#define PIT_PERIOD_1000ms 		(0x174A63)
#define PIT_PERIOD_10000ms 		(0xE89A7E7)

void PIT_setStrtVal(int periodms);
void PIT_restart();
void PIT_start();
int PIT_readTime();
void init_PIT_IRQ(int periodms);

#endif