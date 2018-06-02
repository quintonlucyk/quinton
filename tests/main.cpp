#include <Cosa/Trace.hh>
#include <Cosa/UART.hh> // for serial
#include "Cosa/RTT.hh"
#include "SDC2160S.h"

wlp::SDC2160S sdc_a(Board::PWM0);


void setup() {
    RTT::begin();
    uart.begin(9600); // baud
    trace.begin(&uart);
}

void loop() {
	sdc_a.set_speed( 20 );
	delay(1000);
	sdc_a.set_speed( 40 );
	delay(1000);
	sdc_a.set_speed( 60 );
	delay(1000);
	sdc_a.set_speed( 80 );
	delay(1000);	
}
