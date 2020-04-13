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

#ifndef BSP_NUCLEO_F446_GPIO_H_
#define BSP_NUCLEO_F446_GPIO_H_

#include <stm32f4xx_ll_gpio.h>

#include <stdint.h>
#include <stdbool.h>

#include "bsp/bsp.h"

/**
 * @brief Gerneric pin definitions.
 */
#define BSP_GPIO_PIN_0                      (LL_GPIO_PIN_0)
#define BSP_GPIO_PIN_1                      (LL_GPIO_PIN_1)
#define BSP_GPIO_PIN_2                      (LL_GPIO_PIN_2)
#define BSP_GPIO_PIN_3                      (LL_GPIO_PIN_3)
#define BSP_GPIO_PIN_4                      (LL_GPIO_PIN_4)
#define BSP_GPIO_PIN_5                      (LL_GPIO_PIN_5)
#define BSP_GPIO_PIN_6                      (LL_GPIO_PIN_6)
#define BSP_GPIO_PIN_7                      (LL_GPIO_PIN_7)
#define BSP_GPIO_PIN_8                      (LL_GPIO_PIN_8)
#define BSP_GPIO_PIN_9                      (LL_GPIO_PIN_9)
#define BSP_GPIO_PIN_10                     (LL_GPIO_PIN_10)
#define BSP_GPIO_PIN_11                     (LL_GPIO_PIN_11)
#define BSP_GPIO_PIN_12                     (LL_GPIO_PIN_12)
#define BSP_GPIO_PIN_13                     (LL_GPIO_PIN_13)
#define BSP_GPIO_PIN_14                     (LL_GPIO_PIN_14)
#define BSP_GPIO_PIN_15                     (LL_GPIO_PIN_15)
#define BSP_GPIO_PIN_All                    (LL_GPIO_PIN_ALL)

/**
 * @brief Derives a bsp internal gpio ID from the given port and pin.
 */
#define BSP_IOMAPVAL(_port, _pin)           ((_port << 16) + _pin)

/**
 * @brief Descriptor of all gpio pins. Hence that some of those names might be
 * overwritten in bsp.h as there special function pins names will be mapped
 * the the generic gpio names.
 */
typedef enum
{
    BSP_GPIO_A0        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_A1        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_A2        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_A3        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_A4        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_A5        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_A6        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_A7        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_A8        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_A9        = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_A10       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_A11       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_A12       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_A13       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_A14       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_A15       = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_A_ALL     = BSP_IOMAPVAL(GPIOA_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_B0        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_B1        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_B2        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_B3        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_B4        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_B5        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_B6        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_B7        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_B8        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_B9        = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_B10       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_B11       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_B12       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_B13       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_B14       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_B15       = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_B_ALL     = BSP_IOMAPVAL(GPIOB_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_C0        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_C1        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_C2        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_C3        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_C4        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_C5        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_C6        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_C7        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_C8        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_C9        = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_C10       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_C11       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_C12       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_C13       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_C14       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_C15       = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_C_ALL     = BSP_IOMAPVAL(GPIOC_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_D0        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_D1        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_D2        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_D3        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_D4        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_D5        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_D6        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_D7        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_D8        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_D9        = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_D10       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_D11       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_D12       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_D13       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_D14       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_D15       = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_D_ALL     = BSP_IOMAPVAL(GPIOD_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_E0        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_E1        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_E2        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_E3        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_E4        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_E5        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_E6        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_E7        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_E8        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_E9        = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_E10       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_E11       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_E12       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_E13       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_E14       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_E15       = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_E_ALL     = BSP_IOMAPVAL(GPIOE_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_F0        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_F1        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_F2        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_F3        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_F4        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_F5        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_F6        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_F7        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_F8        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_F9        = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_F10       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_F11       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_F12       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_F13       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_F14       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_F15       = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_F_ALL     = BSP_IOMAPVAL(GPIOF_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_G0        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_G1        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_G2        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_G3        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_G4        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_G5        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_G6        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_G7        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_G8        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_G9        = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_G10       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_G11       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_G12       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_G13       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_G14       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_G15       = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_G_ALL     = BSP_IOMAPVAL(GPIOG_BASE, BSP_GPIO_PIN_All),

    BSP_GPIO_H0        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_0),
    BSP_GPIO_H1        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_1),
    BSP_GPIO_H2        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_2),
    BSP_GPIO_H3        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_3),
    BSP_GPIO_H4        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_4),
    BSP_GPIO_H5        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_5),
    BSP_GPIO_H6        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_6),
    BSP_GPIO_H7        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_7),
    BSP_GPIO_H8        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_8),
    BSP_GPIO_H9        = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_9),
    BSP_GPIO_H10       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_10),
    BSP_GPIO_H11       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_11),
    BSP_GPIO_H12       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_12),
    BSP_GPIO_H13       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_13),
    BSP_GPIO_H14       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_14),
    BSP_GPIO_H15       = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_15),
    BSP_GPIO_H_ALL     = BSP_IOMAPVAL(GPIOH_BASE, BSP_GPIO_PIN_All),

}bspGpioPin_t;

/**
 * @brief Used to initialize a single gpio pin.
 *
 * @param pin   The bsp gpio pin ID.
 * @param init  Parameters to use. Hence the pin number given by this struct
 *              will be overwritten by the number derived from the pin ID.
 */
void bspGpioPinInit(bspGpioPin_t pin, LL_GPIO_InitTypeDef *init);

/**
 * @brief Used to initialize gpio pins used by the bsp internally.
 * 
 * E.g. tty, led, buttons, etc.
 */
void bspGpioInit(void);

/**
 * @brief Sets the given gpio pins to high.
 *
 * Hence that althow only one pin value can be passed, it is still possible that
 * more than one pin is specified. See BSP_GPIO_x_ALL for a example.
 * 
 * @param pin   The bsp gpio pin ID.
 */
void bspGpioSet(bspGpioPin_t pin);

/**
 * @brief Sets the given gpio pin to low.
 * 
 * Hence that althow only one pin value can be passed, it is still possible that
 * more than one pin is specified. See BSP_GPIO_x_ALL for a example.
 * 
 * @param pin
 */
void bspGpioClear(bspGpioPin_t pin);

/**
 * @brief Toggels the given gpio pins.
 *
 * Hence that althow only one pin value can be passed, it is still possible that
 * more than one pin is specified. See BSP_GPIO_x_ALL for a example.
 * 
 * @param pin   The bsp gpio pin ID.
 */
void bspGpioToggle(bspGpioPin_t pin);

/**
 * @brief Sets the given gpio pins based on the given value.
 *
 * @param pin   The bsp gpio pin ID.
 * @param val   If true the pins will be set to high.
 *              If false the pins will become low.
 */
void bspGpioWrite(bspGpioPin_t pin, uint32_t val);

/**
 * @brief Used to read the given gpio pins.
 * 
 * Hence that althow only one pin value can be passed, it is still possible that
 * more than one pin is specified. See BSP_GPIO_x_ALL for a example.
 *
 * @param pin   The pins to read. 
 *
 * @return  true    if the pin is high.
 *          false   if the pin is low.
 */
bool bspGpioRead(bspGpioPin_t pin);

#endif /* BSP_NUCLEO_F446_GPIO_H_ */
