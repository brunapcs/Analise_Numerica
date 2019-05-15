
#include "integral.h"
#include <stdio.h>
#include <math.h> 


double f(double x){
    //printf("oi");
    return cos(x)- 2*sin(x);
}

double analitica(double x){
    return sin(x)+ 2*cos(x);
}

double f1(double x ){
    return x/(sqrt(x*x + 9));
}
double f2(double x){
    return x*x*log(x);
}
double f3(double x){
    return x*x*sin(x);
}

double derivada(double(*f)(double x), double x , double h){
    //printf("valor: %lf\n" , ((*f)(x + h) - (*f)(x - h))/(2*h) );
    return ((*f)((x+h)) - (*f)(x - h))/(2*h);
}

double h_otimo(double(*f)(double x), double(*f1)(double x), double x){
    double menor, erro, melhor_h;
    for(double h = 0.1  ; h>=0.00000000001; h= h*(0.1)){
        erro = (*f1)(x) - derivada( (*f) , x , h ) ;
        if(h == 0.1){
            menor = erro;
            melhor_h = h;
        }
        else if(erro <= menor){
            menor = erro;
            melhor_h = h;
        }
    }
    return melhor_h;
}
double simpson(double (*f)(double x), double a, double b, int n){
    double pto_med = (a+b)/2;
    double inte = ((b-a)/n)*((*f)(a)+(4*(*f)(pto_med))+ (*f)(b));
    return inte;
}
double pontomedio (double (*f) (double), double a, double b, int n){
    double pto = (a+b)/2;
    return ((b-a)/n)*(*f)(pto);
}
