#include "taylor.h"
#include <stdio.h>
#include <math.h>

double fsqrt (double x){
    double x0 =1 , c = 1.5;
    return  1 + 0.5*(x-x0) -0.125*(pow(x-x0, 2)) + 0.0625*(pow(x-x0, 3)) - ((0.9375/(pow(c, 3.5)))/24)*(pow(x-x0, 4));
}

double fsqrt_erro (double x){
    double maior= 0 , num = 0 , c= 1;
    while( c<=2 ){
        num= (0.9375/(pow(c, 3.5))/24)*(pow(x-1,4));
        if (num > maior)
            maior= num;
        c+=0.1;
    }
    return maior;
}

double fcossin (double x){
    return (1-0.5*pow((2.0*x),2)) + 2.0* (x+(-1.0/6)*pow(x,3));
}
double fcossin_erro(double x){
    return fabs( 1.0 /24 * (1 -0.5*pow((2*x),2)) * (pow(3.14, 4))) + fabs(1.0 / 12.0 * 2.0 * (x+(-1.0/6)*pow(x,3)) *pow(3.14, 4) );
}
