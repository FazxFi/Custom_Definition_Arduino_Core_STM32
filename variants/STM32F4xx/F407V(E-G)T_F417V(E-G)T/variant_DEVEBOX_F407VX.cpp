/*
 *******************************************************************************
 * Copyright (c) 2017-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_DEVEBOX_F407VE) || defined(ARDUINO_DEVEBOX_F407VG)

#include "pins_arduino.h"

// Digital PinName array
// This array allows to wrap Arduino pin number(Dx or x)
// to STM32 PinName (PX_n)
const PinName digitalPin[] = {
  // Right Side
  //Int   //Ext
  //3V3,   3V3
  //GND,   GND
  //GND,   GND
  //VDDA,  VREF+
  PB14,	  PB13,   	// D0, D1
  PB12,	  PB11,
  PB10,	  PE15,
  PE14,	  PE13,
  PE12,	  PE11,   	
  PE10,	  PE9,		// D10, D11
  PE8, 	  PE7,
  PB1, 	  PB0,
  PC5, 	  PC4,
  PA7, 	  PA6,
  PA5, 	  PA4,		//D20, D21
  PA3, 	  PA2,
  //PA1,    PA0,//  // PA_1, PA_0: Moved to allow contiguous analog pins
  PC3, 	  PC2,
  PC1, 	  PC0,		
  PA1,    PA0,
  PE6,    PE5,		//D30, D31
  PE4,    PE3,
  PE2,				//D34
  // Left Side
  //Ext   //Int
  //5V,     5V,
  //3V3,    3V3,
  //GND,    GND,
  PD8,    PB15,
  PD10,   PD9,
  PD12,   PD11,		//D39, D40
  PD14,   PD13,
  PC6,    PD15,
  PC8,    PC7,
  PA8,    PC9,		
  PA10,   PA9,		//D49, D50
  PA12,   PA11,
  PC10,   PA15,
  PC12,   PC11,
  PD1,    PD0,		
  PD3,    PD2,		//D59, D60
  PD5,    PD4,
  PD7,    PD6,
  PB5,    PB3,
  PB7,    PB6,		
  PB9,    PB8,		//D69, D70
  PE1,    PE0
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  14, // A0
  15, // A1
  16, // A2
  17, // A3
  18, // A4
  19, // A5
  20, // A6
  21, // A7
  22, // A8
  23, // A9
  24, // A10
  25, // A11
  26, // A12
  27, // A13
  28, // A14
  29  // A16

};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /**Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    Error_Handler();
  }

  /* Ensure CCM RAM clock is enabled */
  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE();

}

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_DEVEBOX__F407VE || ARDUINO_DEVEBOX_F407VG */
