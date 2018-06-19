#ifndef GOOSE_CONTROLLER_SDC2160S_H
#define GOOSE_CONTROLLER_SDC2160S_H

#include <Cosa/PWMPin.hh>

namespace wlp {

    class SDC2160S {
    public:
        explicit SDC2160S(Board::PWMPin pwm_pin);

        void set_speed(const int speed);
		
		void begin();

    private:
        PWMPin m_pwm_pin;
    };

}

#endif //GOOSE_CONTROLLER_SDC2160S_H