#include "integral.h"
#include <stdio.h>
#include <math.h>
#include "simpson.h"


double f1(double x){
    return (x / sqrt(pow(x,2) + 9 ));
}

double f2( double x){
    return exp(-(x*x)/2 );
}

double f3(double x){
    return exp(-(x*x));
}

int main() {
    
    double resp1 = AdaptiveSimpson ( 0 , 1 , &f1 , 0.0000001);
    printf("Funcao 1 Pelo Adaptive Simpson : %.7lf\n" , resp1);
    
    double resp2 = (1/sqrt(2*M_PI))*Quadratura2(-1, 1, &f2);
    printf("Funcao 2 Pela quadratura 2 :%lf\n" , resp2);
    
    double resp3 = (2/sqrt(M_PI))*Quadratura3(0, 3, &f3 );
    printf("Funcao 3 Pela quadratura 3 : %lf",  resp3);
    
    return 0;
}
