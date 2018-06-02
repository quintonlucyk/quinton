#include <Cosa/Trace.hh>
#include "SDC2160S.h"

#define SCALE_1 2.4693877551 // (184-63)/49
#define SCALE_2 1.26530612245 // (253-191)/49

using namespace wlp;

SDC2160S::SDC2160S(Board::PWMPin PWM_pin)
    : m_pwm_pin(PWM_pin) {}

void SDC2160S::set_speed(const double speed) {
	// not processing speed < 0 or > 100
    
	int scaled_speed = 0;
	
	if (speed < 0 || speed > 100)
		scaled_speed = 0; //writing zero to pin to clear (instead of set)
	else if (speed == 50)
		scaled_speed = 190;
	else if (0 <= speed && speed < 50)//need to map speeds 0-49 to 63-184 for scaled_speed
		scaled_speed = (speed*SCALE_1) + 63;
	else if (50 < speed && speed <= 100)//need to map speeds 51-100 to 191-253 for scaled_speed
		scaled_speed = ((speed-51)*SCALE_2) + 191;
	
	uint8_t pwm_write = static_cast<uint8_t>(scaled_speed);
    m_pwm_pin.write(pwm_write);
}