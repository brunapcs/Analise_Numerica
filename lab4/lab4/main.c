#include "sistlinear.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

#define TAM 3 

int main(){
	
    // teste com a matriz 3x3
   /* int *vet;
    double **m = matcria(3, 3);
    double *x;
    double b[3];
    
    b[0] = 3;
    b[1] = 3;
    b[2] = -6;
    
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2]= -1;
    
    m[1][0] = 2;
    m[1][1] = 1;
    m[1][2]= -2;
    m[2][0] = -3;
    m[2][1] = 1;
    m[2][2]= 1;
   
    
    matimprime(3, 3 , m , "%.2lf");

    vet = fatoracao (3, m);
    matimprime(3, 3 , m , "%0.2lf");
    x = substituicao (3, m, vet,b);
    vetimprime(3, x , "%0.2lf" );

    vetlibera(x);
    matlibera(3,m);
   
   */
    
    //teste com a matriz 6x6
    
    
    int *vet;
    double **m = matcria(6, 6);
    double *x;
    double b[6];
   
    m[0][0] = 3;
    m[0][1] = -1;
    m[0][2]= 0;
     m[0][3]= 0;
     m[0][4]= 0;
     m[0][5]= 0.5 ;
    
    m[1][0] = -1;
    m[1][1] = 3;
    m[1][2]= -1;
      m[1][3]= 0;
      m[1][4]= 0.5;
      m[1][5]= 0;
    
    
    
    m[2][0] = 0;
    m[2][1] = -1;
    m[2][2]= 3;
     m[2][3]= -1;
     m[2][4]= 0;
     m[2][5]= 0;
    
    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2]= -1;
    m[3][3]= 3;
    m[3][4]= -1;
    m[3][5]= 0;
    
    m[4][0] = 0;
    m[4][1] = 0.5;
    m[4][2]= 0;
    m[4][3]= -1;
    m[4][4]= 3;
    m[4][5]= -1;
    
    m[5][0] = 0.5;
    m[5][1] = 0;
    m[5][2]= 0;
    m[5][3]= 0;
    m[5][4]= -1;
    m[5][5]= 3;
    
    
    b[0] = 2.5;
    b[1] = 1.5;
    b[2] = 1;
    b[3] = 1;
    b[4] = 1.5;
    b[5] = 2.5;
    
    matimprime(6, 6 , m , "%.2lf");
    
    vet = fatoracao (6, m);
    matimprime(6, 6 , m , "%0.2lf");
    x = substituicao (6, m, vet,b);
    vetimprime(6, x , "%0.2lf" );
    
    vetlibera(x);
    matlibera(6,m);
	return 0;
}
