#ifndef _BODY_HPP_
#define _BODY_HPP_

#include <utility>
#include "Integrator.hpp"
class Integrator;

class Body {
    // Yes, the internal state of this thing is being made public.
    // The Body should always be a private member of some other class,
    // and that class should not publically expose its body (oh my!)
    public :
        double mass;    // Current mass of the vehicle
        double I_yy;    // Moment of inertia pointing 'out of the screen'
        std::pair<double, double> position;  // Centre of mass position
        std::pair<double, double> velocity;  // Centre of mass velocity
        double theta;   // Rotation angle
        double omega_y;

        bool attached_to_integrator;    // Used to make sure we only attach to one integrator
    public :
        Body(double mass, double I_yy);
        Body(double mass, double I_yy,
             std::pair<double, double> position,
             std::pair<double, double> velocity,
             double theta, double omega_y);

        void attach_to_integrator(Integrator* integrator);
};

#endif
