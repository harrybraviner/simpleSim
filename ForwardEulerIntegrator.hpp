#ifndef _FORWARDEURLERINTEGRATOR_HPP_
#define _FORWARDEURLERINTEGRATOR_HPP_

#include "Integrator.hpp"

class ForwardEulerIntegrator : public Integrator {
    public :
        void update(double dt);
};

#endif
