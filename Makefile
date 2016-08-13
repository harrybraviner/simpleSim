TestSims : TestSims.cpp
	g++ -Wall TestSims.cpp InertBall.o ForwardEulerIntegrator.o Integrator.o Body.o -o TestSims -std=c++17

InertBall.o : InertBall.hpp InertBall.cpp
	g++ -Wall -c InertBall.cpp -std=c++17

ForwardEulerIntegrator.o : ForwardEulerIntegrator.hpp ForwardEulerIntegrator.cpp Integrator.hpp Body.hpp
	g++ -Wall -c ForwardEulerIntegrator.cpp -std=c++17

Integrator.o : Integrator.hpp Integrator.cpp Body.hpp
	g++ -Wall -c Integrator.cpp -std=c++17

Body.o : Body.hpp Body.cpp
	g++ -Wall -c Body.cpp -std=c++17

BasicVehicle.o : BasicVehicle.hpp BasicVehicle.cpp
	g++ -Wall -c BasicVehicle.cpp -std=c++17
