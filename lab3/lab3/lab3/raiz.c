#include <stdio.h> 
#include "raiz.h" 
#include <math.h> 

//FUNCOES PARA EX 1 
double f(double x){   
    return cos(x) - pow(x,3) + x;
} 
double f1(double x){ 
    return - sin(x) -3*pow(x,2)+1;
} 

int NR(double x0, int p, double (*f)(double x), double(*f1)(double x), double *r){ 
	double erro = 0.5*pow(10.0, -p);
	int i;

	//caso x0 ja seja o resultado
    if( fabs((*f)(x0)) <= erro)
        return 1;
    

	//metodo de Newton 
	for(i=1; i<50; i++){ 
		*r = x0 - ((*f)(x0)/(*f1)(x0));
        if(fabs((*f)(*r))<=erro || fabs(*r-x0) <= erro)
            return i;
		x0= *r; 
	} 
	//sai do loop se nao convergir
	return 0; 
} 

//Det 3x3 
double det(double v[3][3]){
   double p=(+((v[0][0]*v[1][1]*v[2][2])+(v[0][1]*v[1][2]*v[2][0])+(v[0][2]*v[1][0]*v[2][1])));
   double  m=(-((v[0][2]*v[1][1]*v[2][0])+(v[0][0]*v[1][2]*v[2][1])+(v[0][1]*v[1][0]*v[2][2])));
    double nt=p+m;
	return nt;
} 

double Crammer(double x0, double x1, double x2, double(*f)(double x)){ 
	double detAc , detA; 
	double A[3][3], Ac[3][3];  

    
	Ac[0][0] = pow((*f)(x0), 2); 
	Ac[1][0] = pow((*f)(x1), 2); 
	Ac[2][0] = pow((*f)(x2), 2); 

	Ac[0][1] = (*f)(x0); 
	Ac[1][1] = (*f)(x1); 
	Ac[2][1] = (*f)(x2); 

	Ac[0][2] = x0;
	Ac[1][2] = x1; 
	Ac[2][2] = x2; 
  

	detAc = det(Ac); 

    
	A[0][0] = pow((*f)(x0), 2); 
	A[1][0] = pow((*f)(x1), 2); 
	A[2][0] = pow((*f)(x2), 2); 
	
	A[0][1] = (*f)(x0); 
	A[1][1] = (*f)(x1); 
	A[2][1] = (*f)(x2); 

	A[0][2] = 1;
	A[1][2] = 1;
	A[2][2] = 1;

	detA = det(A);

	return (detAc/detA); 
} 


int IQI (double x0, double x1, double x2, int p, double(*f)(double x) , double *r){ 
	double	erro = 0.5 * pow(10.0, -p);  
	int i; 

	for(i=0; i<50; i++){
        *r= Crammer(x0, x1, x2, f);

		if(fabs((*f)(*r))< erro)
			return i; 
		x0=x1; 
		x1 = x2; 
		x2 = *r; 
	} 

	//nao houve convergencia
   printf("Nao convergiu");
	return 0; 

} 
