#include <Cosa/Trace.hh>
#include <Cosa/UART.hh> // for serial
#include "Cosa/RTT.hh"
#include "SDC2160S.h"

wlp::SDC2160S sdc(Board::PWM0);


void setup() {
    RTT::begin();
    uart.begin(9600); // baud
    trace.begin(&uart);
}

void loop() {
	sdc( -1 );
	delay(1000);
}
