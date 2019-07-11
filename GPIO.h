#ifndef GP_IO
#define GP_IO

#define PORT_PCR_GPIO_MASK 		(PORT_PCR_ISF_MASK | \
                                    	    (1u << PORT_PCR_MUX_SHIFT))

struct SGPIO{
	uint8_t PORT;
	uint8_t pin;
	uint8_t dir;
};

uint8_t init_GPIO(struct SGPIO pininfo[], uint8_t numPins);
uint8_t GPIO_write(struct SGPIO *pininfo, uint8_t val);
uint8_t GPIO_read(struct SGPIO *pininfo);

#endif
