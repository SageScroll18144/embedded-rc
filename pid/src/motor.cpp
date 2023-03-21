#include "mbed.h"
#include "motor.h"

Motor::Motor(int pin_motor, int velocity);
void Motor::setVelocity(int motor, int value);
