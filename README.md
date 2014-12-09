Integrator
==========

Numerical solution to the forced Duffing oscillator


This program computes a numerical solution to the forced Dufﬁng
oscillator with parameters \delta =0.2, \gamma=0.3 and \omega=1.

The interface provides three different implementations of the integrator:

1) Explicit Euler
2) Second-order Adams-Bashforth
3) Fourth-order Runge-Kutta

The program takes two inputs, the time step and the number of steps to be taken.
The output files are duffing_euler, duffing_rk4 and duffing_ab2 for the respective methods
of integration. The output files can be run as:

./duffing_euler 0.1 100

which prints out t, x and x' for different time steps.
