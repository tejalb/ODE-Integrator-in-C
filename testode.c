#include "integrator.h"
// Forced duffing oscillator
const double delta=0.2;
const double gamma=0.3;
const double omega=1;

int nsteps=1000;
double tstep=1e-3;


int myfunc(int n, double t, const double *x, double *fx) {
  for (int i=0;i<n;i++){
    fx[i]=-x[i];
  }
  return 0;
}

int main()
{
  
  Integrator *my_integrator = integrator_new(1,tstep,&myfunc);
  double t0=0.0;
  double x[1];
  x[0]=1.0;
  for(int i=0;i<nsteps;i++) {
    integrator_step( my_integrator,t0,x);
    t0+=tstep;
  }
  printf("The answer is %f\n",x[0]); 
  integrator_free(my_integrator);
  return 0;
} 
