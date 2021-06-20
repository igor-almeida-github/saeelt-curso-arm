/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Jun 3, 2021
 *      Author: igor
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/****************************************************************
 *                  TYPEDEFS STRUCT                              *
 ****************************************************************/

typedef struct{

	uint8_t Pin_Number;        /* !< possible values in @GPIO_PIN_NUMBERS*/
	uint8_t Pin_Mode;
	uint8_t Pin_Output_Type;
	uint8_t Pin_Output_Speed;
	uint8_t Pin_Pull_Up_Pull_Down;
	uint8_t Pin_Alternate_Function;

}GPIO_PinConfig_t;

typedef struct{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/****************************************************************
 *                     MACROS                                   *
 ****************************************************************/

// @GPIO_PIN_NUMBERS
#define GPIO_PIN_NO_0     0
#define GPIO_PIN_NO_1     1
#define GPIO_PIN_NO_2     2
#define GPIO_PIN_NO_3     3
#define GPIO_PIN_NO_4     4
#define GPIO_PIN_NO_5     5
#define GPIO_PIN_NO_6     6
#define GPIO_PIN_NO_7     7
#define GPIO_PIN_NO_8     8
#define GPIO_PIN_NO_9     9
#define GPIO_PIN_NO_10   10
#define GPIO_PIN_NO_11   11
#define GPIO_PIN_NO_12   12
#define GPIO_PIN_NO_13   13
#define GPIO_PIN_NO_14   14
#define GPIO_PIN_NO_15   15

// @GPIO_PIN_MODE
#define GPIO_PIN_MODE_INPUT     0
#define GPIO_PIN_MODE_OUTPUT    1
#define GPIO_PIN_MODE_ALT_FUNC  2
#define GPIO_PIN_MODE_ANALOG    3

// @GPIO_PIN_OUTPUT_TYPES
#define GPIO_PIN_PUSH_PULL  0
#define GPIO_PIN_OPEN_DRAIN 1

// @GPIO_PIN_OUTPUT_SPEED
#define GPIO_PIN_SPEED_LOW         0
#define GPIO_PIN_SPEED_MEDIUM      1
#define GPIO_PIN_SPEED_HIGH        2
#define GPIO_PIN_SPEED_VERY_HIGH   3

// @GPIO_PIN_PULL_UP_PULL_DOWN
#define GPIO_PIN_NO_PU_PD    0
#define GPIO_PIN_PULL_UP     1
#define GPIO_PIN_PULL_DOWN   2

// @GPIO_PIN_ALTERNATE_FUNCTION
#define GPIO_PIN_AF0     0
#define GPIO_PIN_AF1     1
#define GPIO_PIN_AF2     2
#define GPIO_PIN_AF3     3
#define GPIO_PIN_AF4     4
#define GPIO_PIN_AF5     5
#define GPIO_PIN_AF6     6
#define GPIO_PIN_AF7     7
#define GPIO_PIN_AF8     8
#define GPIO_PIN_AF9     9
#define GPIO_PIN_AF10   10
#define GPIO_PIN_AF11   11
#define GPIO_PIN_AF12   12
#define GPIO_PIN_AF13   13
#define GPIO_PIN_AF14   14
#define GPIO_PIN_AF15   15


/****************************************************************
 *                  APIs PROTOTYPES                             *
 ****************************************************************/

/* GPIO initialization */
void GPIO_Pin_Init(GPIO_Handle_t *pGPIO_Handle);

/* Pin Read and Write*/
uint8_t GPIO_Pin_DigitalRead(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_Pin_DigitalWrite(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t PinState);

/* Pin Toggle */
void GPIO_Pin_Toggle(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/* Port Read and Write */
uint16_t GPIO_Port_DigitalRead(GPIO_RegDef_t *pGPIOx);
void GPIO_Port_DigitalWrite(GPIO_RegDef_t *pGPIOx, uint16_t Data);

/* Clock Enable */
void GPIO_CLK_Enable(GPIO_RegDef_t *pGPIOx);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */









