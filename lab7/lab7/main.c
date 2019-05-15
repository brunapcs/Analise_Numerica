#include <stdio.h>
#include <math.h>
#include "integral.h"


int main(int argc, const char * argv[]) {
    double s , ptoMed;
    double m = h_otimo(&f, &analitica, 20);
    printf("h teorico = 0.1 , h que minimiza :%lf\n " , m );
    
    printf("SIMPSON\n\n");
    s = simpson(&f1, 0 , 4 , 16);
    printf("f1 com passo 16:%lf \n", s);
    s = simpson(&f1, 0 , 4 , 32);
    printf("f1 com passo 32: %lf\n\n", s);

    s = simpson(&f2, 1 , 3 , 16);
    printf("f2 com passo 16: %lf\n", s);
    s = simpson(&f2, 1 , 3 , 32);
    printf("f2 com passo 32:%lf \n\n", s);

    s = simpson(&f3, 0 , M_PI , 16);
    printf("f3 com passo 16: %lf\n", s);
    s = simpson(&f3, 0 , M_PI , 32);
    printf("f3 com passo 32: %lf \n\n", s);
    
    printf("PONTO MEDIO\n\n");
    ptoMed = pontomedio(&f1, 0 , 4 , 16);
    printf("f1 com passo 16:%lf \n", ptoMed);
    ptoMed = pontomedio(&f1, 0 , 4 , 32);
    printf("f1 com passo 32:%lf \n\n", ptoMed);
    
     ptoMed = pontomedio(&f2, 1 , 3 , 16);
    printf("f2 com passo 16:%lf \n", ptoMed);
    ptoMed = pontomedio(&f2, 1 , 3 , 32);
    printf("f2 com passo 32:%lf \n\n", ptoMed);
    
    
    ptoMed = pontomedio(&f3, 0 , M_PI , 16);
    printf("f3 com passo 16:%lf \n", ptoMed);
    ptoMed = pontomedio(&f3, 0 , M_PI , 32);
    printf("f3 com passo 32:%lf \n\n", ptoMed);
    
    
    printf("Sim o passo influencia na resposta e a mais precisa e a regra de Simpson");
    
    return 0;
}
