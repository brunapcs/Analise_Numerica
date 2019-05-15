#include "simpson.h"
#include "integral.h"
#include <stdio.h>
#include <math.h>



double DoubleSimpson (double a, double b, double (*f) (double x), double* v){
    double c = (a+b)/ 2;
    double valor = fabs( simpson (f, a, b, 1) - simpson (f, a, c, 1)
                        -simpson (f, c, b, 1))/15;
    *v = valor+ simpson (f, a, c, 1) + simpson (f, c, b, 1);
    return valor;
}

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol){
    double erro;
    double val = 0;
    erro = DoubleSimpson(a , b, f, &val);
    if(erro<tol)
        return val;
    else
        return AdaptiveSimpson(a, (a+b)/2, f , tol/2) + AdaptiveSimpson((a+b)/2, b, f, tol/2);
}
double Quadratura2 (double a, double b, double (*f) (double x)){
    
    double soma = (*f)(((b-a)*(-sqrt(1.0/3))+b +a)/2)*((b-a)/2);
    soma +=  (*f)(((b-a)*(sqrt(1.0/3))+b +a)/2)*((b-a)/2);
    return soma;
}

double Quadratura3 (double a, double b, double (*f) (double x)){
    double soma=(5.0/9)*(*f)(((b-a)*(-sqrt(3.0/5))+b +a)/2)*((b-a)/2);
    soma += (8.0/9)*(*f)((b+a)/2)*((b-a)/2);
    soma += (5.0/9)*(*f)(((b-a)*(sqrt(3.0/5))+b +a)/2)*((b-a)/2);
    return soma;
}
