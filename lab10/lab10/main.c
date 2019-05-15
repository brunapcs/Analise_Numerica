#include <stdio.h> 
#include <math.h> 
#include "pendulo.h" 

int main(){ 

    

    printf("formula simplificada:%lf\n", periodo_simplificado (1)) ;
    printf(" 1 grau: Calculado:%lf \n", periodo(1));
    printf("retornou"); 
    
    printf("3 grau: Calculado:%lf\n", periodo(3));
    printf("10 grau: Calculado:%lf\n", periodo(10));
    printf("15 grau: Calculado:%lf\n", periodo(15));
    printf("30 grau: Calculado:%lf\n", periodo(30));
    printf("60 grau: Calculado:%lf\n", periodo(60));
    printf("90 grau: Calculado:%lf\n", periodo(90));
    
	return 0;
}
