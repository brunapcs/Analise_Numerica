#include "pendulo.h" 
#include <stdio.h> 
#include <math.h> 


double pendulo (double t, double h, double* theta, double* w){
    double w_0 = *w;
    
    *w = w_0 - h*sqrt(9.8/10)*sin(*theta);
    *theta = *theta + h*w_0;
    
    return t + h;
}


    double periodo (double theta_0){
        double inversoes = 0;
        double theta_i = theta_0;
        double w_i = 0;
        double t = 0;
        
        
        while (inversoes < 10){
            double w_aux = w_i;
            t = pendulo(t, 0.00001, &theta_i, &w_i);
            if (w_aux * w_i < 0) inversoes++;
        }
        return t/5.0;
    }


double periodo_simplificado (double theta_0){
    return 2*M_PI*(sqrt(10/9.8));
}
