/*
 * Blink.cpp
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: yura
 */

#include "Blink.h"


Blink::Blink(TIM_HandleTypeDef *tim) {
	// TODO Auto-generated constructor stub
	this->tim = tim;
}

Blink::~Blink() {
	// TODO Auto-generated destructor stub
}

void Blink::set_brightness(uint32_t brightness){
	this->tim->Instance->CCR1 = brightness;
}

void Blink::blink_sine(uint16_t phase, uint32_t amp, uint8_t const_light){
	auto s = sin(conv_to_rad(phase));
	this->set_brightness((abs(s) * amp) + const_light);
}

void Blink::blink_sine(uint16_t phase, uint32_t amp, uint8_t const_light, float offset){
	auto s = sin(conv_to_rad(phase));
	this->set_brightness((abs(s + offset) * amp) + const_light);
}

float Blink::conv_to_rad(uint16_t deg){
	return (deg * PI) / 180;
}

uint32_t Blink::get_brightness(){
	return this->tim->Instance->CCR1;
}
