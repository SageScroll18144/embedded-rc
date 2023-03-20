#include "PID.h"

double sum = 0;
double last_error = 0;

double proporcional(double curr_point){
  return Kp * (IDEAL - curr_point);
}

double integral(double curr_point){
  sum += (IDEAL - curr_point);
  return Ki * sum;
}

double derivative(double curr_point, double dt){
  double derivative = ((IDEAL - curr_point) - last_error) / dt;
  last_error = (IDEAL - curr_point);
  return Kd * derivative;
}