/*
 * bsp-nucleo-f446, a generic board support package for nucleo-f446 based
 * projects.
 *
 * Copyright (C) 2020 Julian Friedrich
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>. 
 *
 * You can file issues at https://github.com/fjulian79/bsp-nucleo-f446
 */

#include "bsp/bsp.h"
#include "bsp/bsp_exti.h"
#include "bsp/bsp_assert.h"

#include <stm32f4xx_ll_exti.h>

/**
 * @brief Waek declaration of the users button irq callback.
 */
void bspButtonIrqCb(void) __attribute__((weak, alias("bspDefaultExtiCb")));

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Defnition of the default empty handler if the user has not 
 * implemented his own.
 * 
 * ATTENTION: If you end up here a EXTI interrupt has occured and the user has 
 * not implemented the corresponding callback. 
 */
void bspDefaultExtiCb(void)
{
   bspDoAssert();
}

/**
 * @brief Common interrupt handler for all external interrupts.
 * 
 */
void EXTI15_10_IRQHandler(void)
{
   if(LL_EXTI_IsActiveFlag_0_31(BSP_BUTTON_EXTI_LINE) != RESET)
   {
      LL_EXTI_ClearFlag_0_31(BSP_BUTTON_EXTI_LINE);
      bspButtonIrqCb();
   }
   else
   {
      bspDoAssert();
   }
}

#ifdef __cplusplus
}
#endif

void bspExtiInit(void)
{  
   LL_EXTI_InitTypeDef init;

   LL_SYSCFG_SetEXTISource(
         BSP_BUTTON_GPIO_EXTI_PORT, BSP_BUTTON_GPIO_EXTI_LINE); 
 
   LL_EXTI_StructInit(&init);
   init.Line_0_31   = BSP_BUTTON_EXTI_LINE;
   init.LineCommand = ENABLE;
   init.Mode        = LL_EXTI_MODE_IT;
   init.Trigger     = LL_EXTI_TRIGGER_FALLING;
   LL_EXTI_Init(&init);
  
   NVIC_EnableIRQ(EXTI15_10_IRQn); 
   NVIC_SetPriority(EXTI15_10_IRQn, BSP_IRQPRIO_EXTI);
}
