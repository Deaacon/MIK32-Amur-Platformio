#include "mik32_hal_pcc.h"
#include "mik32_hal_gpio.h"

// Выбор платы для конфигурации светодиода
#define BOARD_ACE_UNO
// #define BOARD_NUKE
#include "main.h"

void SystemClock_Config();
void GPIO_Init();

// Инициализация и цикличное мигание светодиода
int main()
{
    SystemClock_Config();
    GPIO_Init();

    while (1)
    {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
        HAL_DelayMs(500);
    }
}

// Функция инициализации тактирования Амура
// Частота работы 32 МГц
void SystemClock_Config(void)
{
    PCC_InitTypeDef PCC_OscInit = {};

    PCC_OscInit.OscillatorEnable = PCC_OSCILLATORTYPE_ALL;
    PCC_OscInit.FreqMon.OscillatorSystem = PCC_OSCILLATORTYPE_OSC32M;
    PCC_OscInit.FreqMon.ForceOscSys = PCC_FORCE_OSC_SYS_UNFIXED;
    PCC_OscInit.FreqMon.Force32KClk = PCC_FREQ_MONITOR_SOURCE_OSC32K;
    PCC_OscInit.AHBDivider = 0;
    PCC_OscInit.APBMDivider = 0;
    PCC_OscInit.APBPDivider = 0;
    PCC_OscInit.HSI32MCalibrationValue = 128;
    PCC_OscInit.LSI32KCalibrationValue = 128;
    PCC_OscInit.RTCClockSelection = PCC_RTC_CLOCK_SOURCE_AUTO;
    PCC_OscInit.RTCClockCPUSelection = PCC_CPU_RTC_CLOCK_SOURCE_OSC32K;

    HAL_PCC_Config(&PCC_OscInit);
}

// Функция инициализации GPIO порта светодиода на вывод
void GPIO_Init()
{
    __HAL_PCC_LED_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {};

    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = HAL_GPIO_MODE_GPIO_OUTPUT;
    GPIO_InitStruct.Pull = HAL_GPIO_PULL_NONE;

    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}
