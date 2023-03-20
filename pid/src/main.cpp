#include "mbed.h"
#include "PID.h"
//pins
DigitalOut led(PTC0);

int main() {
  
  //setup
  double PID, P=0, I=0, D=0;
  
  //loop
  while(1) {
    P = proporcional(0);
    I = integral(0);
    if(0>0) D = derivative(0, 0);

    PID = P + I + D;

    // PID = PID / 4; //A leitura é de 10bits, mas a saida de 4bits!

    led.write(!led.read());
    wait_us(100);
  }
}

/*
  Obs: Erro talvez será simulado internamente, o robo recebe a velocidade e é calculado internamente o quanto foi percorrido, assim o erro é o parametro inicial decrescido da velocidade atual

*/