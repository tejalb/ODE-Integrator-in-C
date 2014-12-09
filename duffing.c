#include "integrator.h"
#include <stdlib.h>
#include <math.h>
// Forced duffing oscillator
const double delta=0.2;
const double gamma=0.3;
const double omega=1;


int myfunc(int n, double t, const double *x, double *fx) {
  fx[0]=x[1];
  fx[1]=x[0]-(x[0]*x[0]*x[0])+(gamma*cos(omega*t))-(delta*x[1]);
  return 0 ; 
}

int main(int argc, char *argv[])
{
  if (argc <3) 
    {
      printf("Not enough input arguments. Please enter time step and number of steps.\n");
      return 0;
    }
  double tstep=atof(argv[1]);
  int nsteps=atoi(argv[2]);
  

  double t0=0.0;
  const  int n=2;
  double x[n];
  x[0]=0.;
  x[1]=0.;
  Integrator *my_integrator = integrator_new(n,tstep,&myfunc);

  
  for(int i=0;i<nsteps;i++) {
    printf("%15.8f %15.8f %15.8f\n",t0,x[0],x[1]);
    integrator_step( my_integrator,t0,x);
    t0+=tstep;
    
  }

  integrator_free(my_integrator);
  return 0;
} 
