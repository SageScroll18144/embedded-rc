#define IDEAL 100

const double Kp = 1;
const double Ki = 1;
const double Kd = 1;

double proporcional(double curr_point);
double integral(double curr_point);
double derivative(double curr_point, double dt);