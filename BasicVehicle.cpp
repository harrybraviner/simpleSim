#include "BasicVehicle.hpp"

#define mass_kg 20.0
#define I_yy 1.0

BasicVehicle::BasicVehicle() {
    this->body = new Body(mass_kg, I_yy);
}
