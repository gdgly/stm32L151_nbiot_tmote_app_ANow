#ifndef __HAL_TEMPERATURE_ADC_H
#define   __HAL_TEMPERATURE_ADC_H

#include "sys.h"

#define TEMPERATURE_ADC_RCC_ADC1_CLK_ENABLE()		__HAL_RCC_ADC1_CLK_ENABLE()
#define TEMPERATURE_ADC_RCC_ADC1_CLK_DISABLE()		__HAL_RCC_ADC1_CLK_DISABLE()

#define TEMPSENSOR_CAL1_ADDR						((uint16_t*) (0x1FF8007AU))
#define TEMPSENSOR_CAL2_ADDR						((uint16_t*) (0x1FF8007EU))
#define TEMPSENSOR_CAL1_TEMP						(( int32_t )  30)
#define TEMPSENSOR_CAL2_TEMP						(( int32_t )  110)
#define TEMPSENSOR_CAL_VREFANALOG					( 3000U)
#define LL_ADC_CALC_TEMPERATURE(__VREFANALOG_VOLTAGE__, __TEMPSENSOR_ADC_DATA__)				\
((((((int32_t)((__TEMPSENSOR_ADC_DATA__ * __VREFANALOG_VOLTAGE__)/ TEMPSENSOR_CAL_VREFANALOG)		\
- (int32_t) *TEMPSENSOR_CAL1_ADDR)) * (int32_t)(TEMPSENSOR_CAL2_TEMP - TEMPSENSOR_CAL1_TEMP))		\
/ (int32_t)((int32_t)*TEMPSENSOR_CAL2_ADDR - (int32_t)*TEMPSENSOR_CAL1_ADDR)) + TEMPSENSOR_CAL1_TEMP)

extern ADC_HandleTypeDef		TEMPERATURE_ADC_Handler;							//内部温度传感器电压ADC句柄

void  TEMPERATURE_ADC_Init(void);											//电压ADC初始化
short TEMPERATURE_ADC_Read(u32 timeout);									//内部温度传感器温度ADC读取

#endif
