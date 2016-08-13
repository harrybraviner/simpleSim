#include "Integrator.hpp"

Integrator::Integrator() {

}

void Integrator::attach_body(Body* body) {
    bodies.push_back(body);
}
