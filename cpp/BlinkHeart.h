/*
 * Heart.h
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: yura
 */

#ifndef BLINKHEART_H_
#define BLINKHEART_H_

#include "Blink.h"
#include "stm32f0xx_hal.h"
#include "main.h"
#include <random>

#define PI 3.14159265

class BlinkHeart {
public:
	BlinkHeart(Blink *R, Blink *G, Blink *B);
	virtual ~BlinkHeart();

	void blink_heart(uint16_t bright, uint8_t speed_delay, uint16_t pause, uint8_t repeats);
	void blink_rand_color_sine(uint16_t bright, uint16_t speed_delay, uint8_t repeats);
	void rainbow(uint16_t speed_delay, uint16_t bright, uint8_t repeats);
	void set_color_rgb(float r, float g, float b, uint16_t bright);
	// Ћинейно ќбнул€ет текущую €ркость до нул€
	void bright_to_zero(uint8_t speed_delay);
	// Ћинейно повышает €ркость до bright
	void bright_to_val(uint16_t bright, uint8_t speed_delay);
	void bright_to_val(uint16_t b_r, uint16_t b_g, uint16_t b_b, uint8_t speed_delay);
	void blink_sine_wave(uint16_t bright, uint8_t speed_delay, uint16_t cont_light, uint8_t repeats);
	void blink_sine_wave_r(uint16_t bright, uint8_t speed_delay, uint16_t cont_light, uint8_t repeats);

	void blink_super_heart(uint16_t bright, uint8_t speed_delay, uint16_t pause, uint8_t repeats);

public:
	Blink *r = nullptr;
	Blink *g = nullptr;
	Blink *b = nullptr;
};


#endif /* BLINKHEART_H_ */
