#include "mbed.h"

#define IDEAL 100

//pins
// DigitalOut led(p21);

//Var
const int Kp = 1;
const int Ki = 1;
const int Kd = 1;

int sum = 0;
int last_error = 0;

double proporcional(int curr_point){
  return Kp * (IDEAL - curr_point);
}

double integral(int curr_point, int dt){
  sum += (IDEAL - curr_point) * dt;
  return Ki * sum;
}

double derivative(int curr_point, int dt){
  double derivative = (double)((IDEAL - curr_point) - last_error) / (double)dt;
  last_error = (IDEAL - curr_point);
  return Kd * derivative;
}

int main() {
  
  //setup
  double P=0, I=0, D=0;
  
  //loop
  while(1) {
    P = proporcional(0);
    I = integral(0, 0);
    if(0>0) D = derivative(0, 0);
  }
}