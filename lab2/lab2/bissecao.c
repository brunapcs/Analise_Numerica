#include<stdio.h> 
#include<math.h> 
#include "bis.h"
#include <stdlib.h> 

double f(double m){ 
	return (9.8*(m)/15)*(1- exp(-(15/m)*9))-35.0; 
} 

double fa(double x){ 
	return 2*pow(x,5) - 4*pow(x, 2) +1; 
}

double fb(double x){
    return sin(x) - 6*x - 5;
}
double fc(double x){
    return tan(x) +5 *pow(x,2) - x;
}
double bissecao(double a, double b, int p, double(*f)(double x)){ 
	
	double erro = 0.5 * (pow(10.0, -p)); 
	double M=0 , x0=0, F; 
	double k  = (log(b-a) - log(erro))/(log(2.0));  
    int i =0; 

	while( fabs(b-a) > erro && i<k){  
		
		M = (*f)(a); 
		x0 = (a+b)/2;
		F = (*f)(x0);
		if(M * F >= 0)
			a = x0; 
		else 
			b = x0; 
		i++; 
	} 
	return x0; 
} 


double* bissecao_multipla(double A, double B, double delta, double(*f)(double x), int *n){ 
	int i = 0;
	double *v;
	double fa= (*f)(A) ,  fb=0;
	int raiz = 0;
    
	//Verificacao do numero de raizes
	while((A+delta*(i+1))<B){
        fb = (*f)(A+(delta*(i+1)));
        if( fa * fb < 0)
            raiz++;
        fa= fb ;
		i++; 
	}
  
	//ALOCACAO
	v = (double*)malloc(raiz*(sizeof(double))); 
	if(v == NULL) { 
		printf("Erro , memoria insuficiente"); 
		exit(1); 
	}
    
    //Calculo de Raizes
    i=0;raiz = 0;fa = (*f)(A);
    while((A+delta*(i+1))<B){
        fb = (*f)(A+(delta*(i+1)));
        if( fa * fb < 0){
            v[raiz]= bissecao(A+delta*i, A+delta*(i+1),  5, f);
            raiz++;
        }
        fa= fb ;
        i++;
    }
    *n = raiz; 
	return v;
} 
