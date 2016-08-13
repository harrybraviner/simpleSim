#ifndef _INERTBALL_HPP_
#define _INERTBALL_HPP_

#include "Body.hpp"

class InertBall {
    private :
        Body* body;
    public :
        InertBall (double radius, double density);
        void attach_to_integrator(Integrator* integrator);
        void set_velocity(std::pair<double, double> velocity);

        std::pair<double, double> get_position();
};

#endif
