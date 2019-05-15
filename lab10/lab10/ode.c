#include <stdio.h> 
#include <math.h> 
#include "ode.h" 


double min(double h, double delta){ 
  if (h<delta)
    return h; 
else 
return delta; 
} 

double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x)){ 
	double x; 
	while(t1 > (t0)){
	 h = min(h, fabs(t1-t0)); 
     x = x0+h*(*f)(t0, x0); 
	 x0 = x; 
	 t0+=h; 
	} 
	 return x; 
} 

double EulerR(double t0, double t1, double h0, double x0,double (*f) (double t, double x), double tol){  
	double x = x0, h = h0, t = t0;  
	double x1, h1, x2, delta; 
    double tole; 
    double  t2 = t0; 
	while(t1 > t){
	 h = min(h, fabs(t1 - t));
     x1= x+h*(*f)(t, x); 
	 h1 = h/2; 
	 x2 = (x+h1*(*f)(t, x)) ;
	 x2 =(x2+h1*(*f)((t+(h/2)), x2)); 
	 
	 delta = fabs(x1-x2); 
	 tole = sqrt(tol/delta);
		 if(tole >=1){ 
			 if(tole >=1.2)
				 tole = 1.2; 
			t+=h;
			x = x2 + delta; 
		 }
		h = tole*h; 
	} 
	return x; 
} 