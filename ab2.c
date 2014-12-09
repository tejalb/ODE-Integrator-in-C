#include "integrator.h"
#include <assert.h>
//Adams-Bashforth
 struct integrator_t {
  int n;
  double dt;
  FuncPtr rhs;
  double *prevk;
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
  free(integrator->prevk);
  free(integrator);
}

int integrator_step(Integrator *integrator, double t, double *x) {
  assert(integrator);
  const int n=  integrator->n;
  double h=integrator->dt;
  double k1[n];
   
  static int firststep=1;	
// First step handled separately	     
  if(firststep==1) {
    firststep=0;
    integrator->prevk=(double *)malloc(n*sizeof(double));
    int iserr=(integrator->rhs)(n,t,x,k1);
    if(!iserr) return iserr;
 
    for(int i=0;i<n;i++) {
    x[i]+=(integrator->dt)*k1[i];
    }
    for(int i=0;i<n;i++){
    integrator->prevk[i]=k1[i];
    }
  } 
  else {
  integrator->rhs(n,t,x,k1);
 
  for(int i=0;i<n;i++) {
    
    x[i]+=(h*1.5)*k1[i] - (h*0.5)*integrator->prevk[i];
  }
    
  for(int i=0;i<n;i++){
    integrator->prevk[i]=k1[i];
   }
  } 
  return 0;
}



  
