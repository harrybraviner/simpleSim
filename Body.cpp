#include "Body.hpp"
#include <exception>

typedef std::pair<double, double> vec2;

Body::Body(double mass, double I_yy)
    : Body(mass, I_yy,
           std::pair<double, double>(0.0, 0.0),
           std::pair<double, double>(0.0, 0.0),
           0.0, 0.0)
{}

Body::Body(double mass, double I_yy,
           std::pair<double, double> position,
           std::pair<double, double> velocity,
           double theta, double omega_y)
    : mass(mass), I_yy(I_yy),
      position(position),
      velocity(velocity),
      theta(theta), omega_y(omega_y),
      attached_to_integrator(false)
{}

void Body::attach_to_integrator(Integrator* integrator) {
    if (this->attached_to_integrator == false) {
        integrator->attach_body(this);
        this->attached_to_integrator = true;
    } else {
        throw std::exception();
    }
}
