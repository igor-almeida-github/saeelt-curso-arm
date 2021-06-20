/*
 * stm32f407xx.h
 *
 *  Created on: Jun 3, 2021
 *      Author: igor
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

/****************************************************************
 *                  GENERIC MACROS                              *
 ****************************************************************/
#define HIGH    1
#define LOW     0
#define SET     1
#define RESET   0

#define __vo    volatile

/****************************************************************
 *                  BASE ADDRESSES                              *
 ****************************************************************/

// GPIO
#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800
#define GPIOD_BASE_ADDRESS  0x40020C00
#define GPIOE_BASE_ADDRESS  0x40021000
#define GPIOF_BASE_ADDRESS  0x40021400
#define GPIOG_BASE_ADDRESS  0x40021800
#define GPIOH_BASE_ADDRESS  0x40021C00
#define GPIOI_BASE_ADDRESS  0x40022000


// RCC
#define RCC_BASE_ADDRESS    0x40023800


/****************************************************************
 *                  TYPEDEFS STRUCT                              *
 ****************************************************************/

// GPIO
typedef struct{

	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;

} GPIO_RegDef_t;

// RCC
typedef struct{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t reserved1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t reserved2;
	__vo uint32_t reserved3;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t reserved4;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t reserved5;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t reserved6;
	__vo uint32_t reserved7;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t reserved8;
	__vo uint32_t reserved9;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
} RCC_RegDef_t;


/****************************************************************
 *                  PERIPHERAL DEFINITIONS                      *
 ****************************************************************/

// GPIO
#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASE_ADDRESS)
#define GPIOI ((GPIO_RegDef_t *)GPIOI_BASE_ADDRESS)

// RCC
#define RCC   ((RCC_RegDef_t *)RCC_BASE_ADDRESS)

#endif /* INC_STM32F407XX_H_ */









