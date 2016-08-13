#ifndef _SIMULATION_HPP_
#define _SIMULATION_HPP_

class Simulation {
    private :
        Body** bodies;
        Integrator *integrator;
    public :
        void attach_body();
        void update_world(double dt);
};

#endif
