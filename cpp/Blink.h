/*
 * Blink.h
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: yura
 */

#ifndef BLINK_H_
#define BLINK_H_

//#include "stm32f0xx_hal.h"
//#include "stdint.h"
#include "math.h"
#include "main.h"

using namespace std;
#define PI 3.14159265

class Blink {
public:
	Blink(TIM_HandleTypeDef *tim);
	virtual ~Blink();

	TIM_HandleTypeDef *tim;
	uint8_t brightness = 0;

	void set_brightness(uint32_t brightness);
	uint32_t get_brightness();
	void blink_sine(uint16_t phase, uint32_t amp, uint8_t const_light);
	void blink_sine(uint16_t phase, uint32_t amp, uint8_t const_light, float offset);
	void blink_pulse();

public:
	static float conv_to_rad(uint16_t deg);

};


#endif /* BLINK_H_ */
