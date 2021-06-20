/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Jun 3, 2021
 *      Author: igor
 */

#include "stm32f407xx_gpio_driver.h"

/*********************************************************************************
 * 						      Private Helper Functions                           *
 *********************************************************************************/

static void write_bits_to_peripheral_reg(__vo uint32_t *pReg, uint8_t bits, uint8_t position, uint8_t no_bits){
	uint32_t Reg_Value = *pReg;

	// 1. Clear bit position
	if(no_bits == 1)
		Reg_Value &= ~(0x1 << position);
	if(no_bits == 2)
		Reg_Value &= ~(0x3 << position);
	if(no_bits == 4)
		Reg_Value &= ~(0xF << position);

	// 2. Write bits to aux variable in "position"
	Reg_Value |= bits << position;

	// 3. Write the data to peripheral register
	*pReg = Reg_Value;

}

/*********************************************************************************
 * 							        APIs                                         *
 *********************************************************************************/

/* GPIO initialization */
void GPIO_Pin_Init(GPIO_Handle_t *pGPIO_Handle){
	uint8_t pin_number = pGPIO_Handle->GPIO_PinConfig.Pin_Number;
	// 0. Enable peripheral clock
	GPIO_CLK_Enable(pGPIO_Handle->pGPIOx);

	// 1. Configure gpio pin mode
	uint8_t pin_mode_bits           = pGPIO_Handle->GPIO_PinConfig.Pin_Mode & 0x3;
	uint8_t pin_mode_bits_position  = 2 * pin_number;
	__vo uint32_t *pMODER = &pGPIO_Handle->pGPIOx->MODER;

	write_bits_to_peripheral_reg(pMODER, pin_mode_bits, pin_mode_bits_position, 2);

	// 2. Configure the output type
	uint8_t output_type_bit           = pGPIO_Handle->GPIO_PinConfig.Pin_Output_Type & 0x1;
	uint8_t output_type_bit_position    = pin_number;
	__vo uint32_t *pOTYPER = &pGPIO_Handle->pGPIOx->OTYPER;

	write_bits_to_peripheral_reg(pOTYPER, output_type_bit, output_type_bit_position, 1);

	// 3. Configure the output speed
	uint8_t output_speed_bits           = pGPIO_Handle->GPIO_PinConfig.Pin_Output_Speed & 0x3;
	uint8_t output_speed_bits_position  = 2 * pin_number;
	__vo uint32_t *pOSPEEDR = &pGPIO_Handle->pGPIOx->OSPEEDR;

	write_bits_to_peripheral_reg(pOSPEEDR, output_speed_bits, output_speed_bits_position, 2);

	// 4. Configure pull-up pull-down resistors
	uint8_t pull_up_pull_down_bits           = pGPIO_Handle->GPIO_PinConfig.Pin_Pull_Up_Pull_Down & 0x3;
	uint8_t pull_up_pull_down_bits_position  = 2 * pin_number;
	__vo uint32_t *pPUPDR = &pGPIO_Handle->pGPIOx->PUPDR;

	write_bits_to_peripheral_reg(pPUPDR, pull_up_pull_down_bits, pull_up_pull_down_bits_position, 2);

	// 5. Configure alternate function choice
	uint8_t alternate_function_bits           = pGPIO_Handle->GPIO_PinConfig.Pin_Alternate_Function & 0xF;
	uint8_t alternate_function_bits_position  = 4 * pin_number;
	__vo uint32_t *pAFRH = &pGPIO_Handle->pGPIOx->AFRH;
	__vo uint32_t *pAFRL = &pGPIO_Handle->pGPIOx->AFRL;

	if(pin_number <= GPIO_PIN_NO_7)
		write_bits_to_peripheral_reg(pAFRL, alternate_function_bits, alternate_function_bits_position, 4);
	else
		write_bits_to_peripheral_reg(pAFRH, alternate_function_bits, alternate_function_bits_position, 4);


}

/* Pin Read and Write*/
uint8_t GPIO_Pin_DigitalRead(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	return (uint8_t)((pGPIOx->IDR >> PinNumber) & 1);
}
void GPIO_Pin_DigitalWrite(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t PinState){
	if(PinState == HIGH)
		pGPIOx->ODR |= (1 << PinNumber);
	else
		pGPIOx->ODR &= ~(1 << PinNumber);
}

/* Pin Toggle */
void GPIO_Pin_Toggle(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (1  << PinNumber);
}

/* Port Read and Write */
uint16_t GPIO_Port_DigitalRead(GPIO_RegDef_t *pGPIOx){
	return (uint16_t)(pGPIOx->IDR);
}

void GPIO_Port_DigitalWrite(GPIO_RegDef_t *pGPIOx, uint16_t Data){
	pGPIOx->ODR = Data;
}

void GPIO_CLK_Enable(GPIO_RegDef_t *pGPIOx){
	uint8_t gpio_bit_number = (pGPIOx == GPIOA)? 0:\
			                  (pGPIOx == GPIOB)? 1:\
					          (pGPIOx == GPIOC)? 2:\
							  (pGPIOx == GPIOD)? 3:\
					          (pGPIOx == GPIOE)? 4:\
							  (pGPIOx == GPIOF)? 5:\
							  (pGPIOx == GPIOG)? 6:\
							  (pGPIOx == GPIOH)? 7:\
							  (pGPIOx == GPIOI)? 8: 0;

    RCC->AHB1ENR |= (1 << gpio_bit_number);
}
