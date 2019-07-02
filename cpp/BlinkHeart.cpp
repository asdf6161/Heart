/*
 * Heart.cpp
 *
 *  Created on: 2 мар. 2019 г.
 *      Author: yura
 */

#include <BlinkHeart.h>

BlinkHeart::BlinkHeart(Blink *R, Blink *G, Blink *B) {
	// TODO Auto-generated constructor stub
	this->r = R;
	this->g = G;
	this->b = B;
}

BlinkHeart::~BlinkHeart() {
	// TODO Auto-generated destructor stub
}

//  bh.blink_heart(100, 20, 1300, 10);
void BlinkHeart::blink_heart(uint16_t bright, uint8_t speed_delay, uint16_t pause, uint8_t repeats){
	for (uint8_t i = 0; i < repeats; ++i) {
		for (uint8_t var = 0; var <= 180; var+=2) {
			this->r->blink_sine(var, bright, 0);
			HAL_Delay(speed_delay);
		}

		for (uint8_t var = 0; var <= 180; var+=2) {
			this->r->blink_sine(var, bright, 0);
			HAL_Delay(speed_delay);
		}
		HAL_Delay(pause);
	}
	this->bright_to_zero(10);
}

void BlinkHeart::blink_rand_color_sine(uint16_t bright, uint16_t speed_delay, uint8_t repeats){
//	srand(this->r->tim->Instance->CNT);
	for (uint8_t i = 0; i < repeats; ++i) {
		uint16_t rng_r = rand()%bright;
		uint16_t rng_g = rand()%bright;
		uint16_t rng_b = rand()%bright;

		for (uint8_t var = 0; var <= 180; var+=1) {
			this->r->blink_sine(var, rng_r, 0);
			this->g->blink_sine(var, rng_g, 0);
			this->b->blink_sine(var, rng_b, 0);
			HAL_Delay(speed_delay);
		}
		this->bright_to_zero(10);
	}
}

void BlinkHeart::rainbow(uint16_t speed_delay, uint16_t bright, uint8_t repeats){

}

void BlinkHeart::set_color_rgb(float r, float g, float b, uint16_t bright){
	this->r->set_brightness((r * bright));
	this->g->set_brightness((g * bright));
	this->b->set_brightness((b * bright));
}


void BlinkHeart::bright_to_zero(uint8_t speed_delay){
	bool c_r = false;
	bool c_g = false;
	bool c_b = false;
	while(!(c_r && c_g && c_b)){
		if (this->r->get_brightness() != 0){
			this->r->set_brightness(this->r->get_brightness() - 1);
		} else {
			c_r = true;
		}
		if (this->g->get_brightness() != 0){
			this->g->set_brightness(this->g->get_brightness() - 1);
		} else {
			c_g = true;
		}
		if (this->b->get_brightness() != 0){
			this->b->set_brightness(this->b->get_brightness() - 1);
		} else {
			c_b = true;
		}
		HAL_Delay(speed_delay);
	}
}

void BlinkHeart::bright_to_val(uint16_t bright, uint8_t speed_delay){
	bool c_r = false;
	bool c_g = false;
	bool c_b = false;
	while(!(c_r && c_g && c_b)){
		if (this->r->get_brightness() != bright){
			this->r->set_brightness(this->r->get_brightness() + 1);
		} else {
			c_r = true;
		}
		if (this->g->get_brightness() != bright){
			this->g->set_brightness(this->g->get_brightness() + 1);
		} else {
			c_g = true;
		}
		if (this->b->get_brightness() != bright){
			this->b->set_brightness(this->b->get_brightness() + 1);
		} else {
			c_b = true;
		}
		HAL_Delay(speed_delay);
	}
}

void BlinkHeart::blink_sine_wave(uint16_t bright, uint8_t speed_delay, uint16_t cont_light, uint8_t repeats){
	for (int repeat = 0; repeat < repeats; ++repeat) {
		uint16_t rng_r = rand()%bright;
		uint16_t rng_g = rand()%bright;
		uint16_t rng_b = rand()%bright;
		this->bright_to_val(cont_light, cont_light, cont_light, speed_delay);
		for (uint8_t var = 0; var <= 180; var+=1) {
			this->r->blink_sine(var, rng_r, cont_light);
			this->g->blink_sine(var, rng_g, cont_light);
			this->b->blink_sine(var, rng_b, cont_light);
			HAL_Delay(speed_delay);
		}
	}
	this->bright_to_zero(speed_delay);
}

void BlinkHeart::blink_sine_wave_r(uint16_t bright, uint8_t speed_delay, uint16_t cont_light, uint8_t repeats){
	this->bright_to_val(cont_light, 0, 0, speed_delay);
	for (int repeat = 0; repeat < repeats; ++repeat) {
		for (uint8_t var = 0; var <= 180; var+=1) {
			this->r->blink_sine(var, bright, cont_light);
			HAL_Delay(speed_delay);
		}
	}
	this->bright_to_zero(speed_delay);
}

void BlinkHeart::bright_to_val(uint16_t b_r, uint16_t b_g, uint16_t b_b, uint8_t speed_delay){
	bool c_r = false;
	bool c_g = false;
	bool c_b = false;
	while(!(c_r && c_g && c_b)){
		if (this->r->get_brightness() != b_r){
			if (this->r->get_brightness() > b_r){
				this->r->set_brightness(this->r->get_brightness() - 1);
			}else {
				this->r->set_brightness(this->r->get_brightness() + 1);
			}
		} else {
			c_r = true;
		}
		if (this->g->get_brightness() != b_g){
			if (this->g->get_brightness() > b_g){
				this->g->set_brightness(this->g->get_brightness() - 1);
			}else {
				this->g->set_brightness(this->g->get_brightness() + 1);
			}
		} else {
			c_g = true;
		}
		if (this->b->get_brightness() != b_b){
			if (this->b->get_brightness() > b_b){
				this->b->set_brightness(this->b->get_brightness() - 1);
			}else {
				this->b->set_brightness(this->b->get_brightness() + 1);
			}
		} else {
			c_b = true;
		}
		HAL_Delay(speed_delay);
	}
}

void BlinkHeart::blink_super_heart(uint16_t bright, uint8_t speed_delay, uint16_t pause, uint8_t repeats){
	for (uint8_t i = 0; i < repeats; ++i) {
		this->bright_to_val(bright, 0, 0, speed_delay);
		this->bright_to_zero(speed_delay);
		HAL_Delay(speed_delay*5);

		this->bright_to_val(bright, 0, 0, speed_delay);
		this->bright_to_zero(speed_delay);
		HAL_Delay(pause);
	}
	this->bright_to_zero(10);
}


















