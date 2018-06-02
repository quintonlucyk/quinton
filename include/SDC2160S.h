#ifndef GOOSE_ESC_SDC2160S_H
#define GOOSE_ESC_SDC2160S_H

#define SCALE_1 2.4693877551 // (184-63)/49
#define SCALE_2 1.26530612245 // (253-191)/49

#include <Cosa/PWMPin.hh>

namespace wlp {

    class SDC2160S {
    public:
        explicit SDC2160S(Board::PWMPin PWM_pin);

        void set_speed(const double speed);

    private:
        PWMPin m_PWM_pin;
    };

}

#endif //GOOSE_ESC_SDC2160S_H