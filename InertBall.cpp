#include "InertBall.hpp"
#include <math.h>

InertBall::InertBall (double radius, double density) {
    double mass = (4.0/3.0)*M_PI*radius*radius; 
    double I_yy = (8.0/15.0)*M_PI*density*pow(radius, 5.0);
    body = new Body(mass, I_yy);

}

void InertBall::attach_to_integrator(Integrator* integrator) {
    this->body->attach_to_integrator(integrator);
}

void InertBall::set_velocity(std::pair<double, double> velocity){
    this->body->position = velocity;
}

std::pair<double, double> InertBall::get_position() {
    std::pair<double, double> position(this->body->position.first,
                                       this->body->position.second);
    return position;
}
