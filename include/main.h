#ifndef __MAIN_H
#define __MAIN_H

// Плата Elbear Ace Uno
#ifdef BOARD_ACE_UNO

// Тактирование порта светодиода и его расположение
#define __HAL_PCC_LED_GPIO_CLK_ENABLE() __HAL_PCC_GPIO_2_CLK_ENABLE()
#define LED_PORT GPIO_2
#define LED_PIN GPIO_PIN_7

#endif // BOARD_ACE_UNO

// Плата Nuke
#ifdef BOARD_NUKE

// Тактирование порта светодиода и его расположение
#define __HAL_PCC_LED_GPIO_CLK_ENABLE() __HAL_PCC_GPIO_0_CLK_ENABLE()
#define LED_PORT GPIO_0
#define LED_PIN GPIO_PIN_10

#endif // BOARD_NUKE

#endif // __MAIN_H
