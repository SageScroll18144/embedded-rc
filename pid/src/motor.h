#include "mbed.h"

class Motor{
    public:
        Motor(int pin_motor, int velocity);
        void setVelocity(int motor, int value);
        void getVelocity(void);
    private:
        int velocity;
        int pin_motor;
};
