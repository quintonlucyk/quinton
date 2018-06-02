#include <Cosa/Trace.hh>
#include "SDC2160S.h"

using namespace wlp;

SDC2160S::SDC2160S(Board::PWMPin PWM_pin)
    : m_PWM_pin(PWM_pin) {}

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
	
	
	
	uint8_t PWM_write = static_cast<uint8_t>(scaled_speed);
    m_PWM_pin.write(PWM_write);
}