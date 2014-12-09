#include "integrator.h"
#include <assert.h>
//Runge-Kutta RK4
 struct integrator_t {
  int n;
  double dt;
  FuncPtr rhs;
};


Integrator *integrator_new(int n, double dt, FuncPtr rhs) {
  Integrator *integrator=(Integrator *)malloc(sizeof(Integrator));
  assert(integrator);
  integrator->n=n;
  integrator->dt=dt;
  integrator->rhs=rhs;
  return integrator;
}

void integrator_free(Integrator *integrator) {
  assert(integrator);
  free(integrator);
}

int integrator_step(Integrator *integrator, double t, double *x) {
  assert(integrator);
  const int n=  integrator->n;
  double k1[n];
  double k2[n];
  double k3[n];
  double k4[n];
  double h=integrator->dt;
  
  
  integrator->rhs(n,t,x,k1);

  double x1[n],x2[n],x3[n];
  for (int i=0;i<n;i++) {
    x1[i]=x[i]+(h/2.)*k1[i];
  }
  
  integrator->rhs(n,t+(h/2),x1,k2);

  for (int i=0;i<n;i++) {
    x2[i]=x[i]+(h/2.)*k2[i];
  }

  integrator->rhs(n,t+(h/2.),x2,k3);

  for (int i=0;i<n;i++) {
    x3[i]=x[i]+h*k3[i];
  }

  integrator->rhs(n,t+h,x3,k4);   // k1,k2,k3,k4 are updated 
 
  for(int i=0;i<n;i++) {
    
    x[i]+=(h/6.0)*k1[i] + (h/3.0)*(k2[i]+k3[i]) + (h/6.0)*k4[i];
  }
  return 0;
}



  

