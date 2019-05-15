#include "bis.h" 
#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 

int main(){ 
	int n, i ; 
    double *v;
	//2
    printf("PRIMEIRO PROBLEMA\n");
	printf("Massa m: %lf" , bissecao(0, 100, 5, &f));


	//4
    printf("\n\n\nSEGUNDO PROBLEMA\n" ); 
    printf("\nFUNCAO A\n");
	 v=bissecao_multipla(-10, 10 , 0.01 , &fa, &n);
	for(i=0; i<n ;i++){
		printf("Raiz: %lf", v[i]);
		printf("\n");
	}
	free(v);
    
    printf("\nFUNCAO B\n");
    v=bissecao_multipla(-10, 10 , 0.01 , &fb, &n);
    for(i=0; i<n ;i++){
        printf("Raiz: %lf", v[i]);
        printf("\n");
    }
    free(v);
    
    printf("\nFUNCAO C\n");
    v=bissecao_multipla(-10, 10 , 0.01 , &fc, &n);
    for(i=0; i<n ;i++){
        printf("Raiz: %lf", v[i]);
        printf("\n");
    }
    free(v);
	return 0; 
}
