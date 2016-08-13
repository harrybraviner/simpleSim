#ifndef _INTEGRATOR_HPP_
#define _INTEGRATOR_HPP_

#include <vector>
#include "Body.hpp"
class Body;

class Integrator {
    protected :
        std::vector<Body*> bodies;
    public :
        virtual void update(double dt) = 0;
        void attach_body(Body* body);

        Integrator();
};

#endif
