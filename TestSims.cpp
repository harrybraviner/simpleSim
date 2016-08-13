#include "InertBall.hpp"
#include "Integrator.hpp"
#include "ForwardEulerIntegrator.hpp"

#include <iostream>
#include <math.h>

using namespace std;

double l2_metric(double x, double y) {
    return sqrt(x*x + y*y);
}

bool within_distance(pair<double, double> expected, pair<double, double> actual, double tolerance) {
    double delta = l2_metric(expected.first - actual.first, expected.second - actual.second);
    return delta <= tolerance;
}

bool within_angle(double expected, double actual, double tolerance) {
    double delta_theta = fmod(expected - actual, 2.0*M_PI);
    return (delta_theta <= tolerance) || (delta_theta - 2.0*M_PI >= - tolerance);
}

void test1() {
    cerr << "Test1: Checking that an inert ball stays at the origin.\n";

    Integrator *forward_euler = new ForwardEulerIntegrator();
    InertBall ball(1.0, 1.0);
    ball.attach_to_integrator(forward_euler);

    pair<double, double> expected_position(0.0, 0.0);

    forward_euler->update(1.0);
    bool right_position = within_distance(expected_position, ball.get_position(), 0.0);
    
    if (right_position) {
        cerr << "\tIn correct position after timestep of 1.0.\n";
    } else {
        cerr << "\tIn wrong position after timestep of 1.0!\n\n\tTest FAILED!\n";
        return;
    }

    forward_euler->update(0.5);
    right_position = within_distance(expected_position, ball.get_position(), 0.0);
    
    if (right_position) {
        cerr << "\tIn correct position after timestep of 0.5.\n";
    } else {
        cerr << "\tIn wrong position after timestep of 0.5!\n\n\tTest FAILED!\n";
        return;
    }

    cerr << "Test 1 PASSED.\n";
}

int main() {

    test1();

    return 0;

}
