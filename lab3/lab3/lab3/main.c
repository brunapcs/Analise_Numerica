#include <stdio.h> 
#include <math.h> 
#include "raiz.h" 

int main(){ 

	double raiz = 0 ; 
    int i;
    //Avaliacao EX 1:
    
    printf("********* Metodo de Newnton *********** \n");
	 i = NR( 4, 6, &f , &f1, &raiz);
    printf("Raiz %lf," , raiz);
	printf("\n iteracoes %d \n" ,i );
    
     i = NR( 1.5, 6, &f , &f1, &raiz);
    printf("Raiz %lf," , raiz);
    printf("\n iteracoes %d \n" ,i );
    
    i = NR( 2, 6, &f , &f1, &raiz);
    printf("Raiz %lf," , raiz);
    printf("\n iteracoes %d" ,i );
    
     printf("\n********* Metodo IQI *********** \n");
    i = IQI (0, 2, 4, 6, &f, &raiz);
    printf("\nRaiz %lf," , raiz);
    printf("\n iteracoes %d" ,i );
    
    i = IQI (0, 1, 2, 6, &f, &raiz);
    printf("\nRaiz %lf," , raiz);
    printf("\n iteracoes %d" ,i );
    
    i = IQI (-2, 2, 4, 6, &f, &raiz);
    printf("\nRaiz %lf," , raiz);
    printf("\n iteracoes %d" ,i );
    
	return 0; 
} 
