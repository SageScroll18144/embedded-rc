#include "mbed.h"

#define IDEAL 100

//pins
DigitalOut led(D5);

//Var
const double Kp = 1;
const double Ki = 1;
const double Kd = 1;

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

int main() {
  
  //setup
  double PID, P=0, I=0, D=0;
  
  //loop
  while(1) {
    P = proporcional(0);
    I = integral(0);
    if(0>0) D = derivative(0, 0);

    PID = P + I + D;

    PID = PID / 4; //A leitura é de 10bits, mas a saida de 4bits!

    led.write(!led.read());
    wait_us(100);
  }
}

/*
  Obs: Erro talvez será simulado internamente, o robo recebe a distancia e é calculado internamente o quanto foi percorrido, assim o erro é o parametro inicial decrescido do calculo de deslocamento

*/