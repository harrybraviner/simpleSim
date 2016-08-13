#include "ForwardEulerIntegrator.hpp"
#include <exception>
#include <math.h>

void ForwardEulerIntegrator::update(double dt) {
    // FIXME - just doing force-free motion for now
    for (Body* body : bodies) {
        body->position.first  += dt * body->velocity.first;
        body->position.second += dt * body->velocity.second;

        body->theta += dt * body->omega_y;
        body->theta = fmod(body->theta, 2.0*M_PI);
    }
}
