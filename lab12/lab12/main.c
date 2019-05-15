#include <stdio.h>
#include <math.h>
#include "vetmat.h"
#include "gradconj.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    double **B;
    double *xb;
    double *bb;
    double tol;
    
    printf("\n====================== MATRIZ A ======================\n");
    
    double **A=  matcria(2, 2);
    A[0][0] = 3;
    A[0][1] = 1 ;
    A[1][0] = 1;
    A[1][1] = 2;
    
    double *b=  vetcria(2);
    b[0] = 5;
    b[1] = 5 ;
    printf(" x[0] = 5 \n x[1] = 5 \n");
    double *x=  vetcria(2);
    x[0] = 5;
    x[1] = 5;
    int k = GradConj(2,A, b, x , pow(10, -7));
    printf("Grad Conjugado: \n numero de iteracoes:%d\n" , k );
    vetimprime(2, x , "%lf");
    x[0] = 5;
    x[1] = 5;
    k= GradConjJacobi(2, A, b , x, pow(10, -7 ));
    printf("Conjugado com Jacobi \n numero de iteracoes:%d \n" , k );
    vetimprime(2, x , "%lf");
    
    printf("\n====================== MATRIZ B ======================");
    printf("\nGradiente Conjugado");
    B = matcria(6, 6);
    B[0][0] =  3; B[0][1] = -1; B[0][2] = 0; B[0][3] = 0; B[0][4] = 0; B[0][5] = 0.5;
    B[1][0] =  -1; B[1][1] = 3; B[1][2] = -1; B[1][3] = 0; B[1][4] = 0.5; B[1][5] = 0;
    B[2][0] =  0; B[2][1] = -1; B[2][2] = 3; B[2][3] = -1; B[2][4] = 0; B[2][5] = 0;
    B[3][0] =  0; B[3][1] = 0; B[3][2] = -1; B[3][3] = 3; B[3][4] = -1; B[3][5] = 0;
    B[4][0] =  0; B[4][1] = 0.5; B[4][2] = 0; B[4][3] = -1; B[4][4] = 3; B[4][5] = -1;
    B[5][0] =  0.5; B[5][1] = 0; B[5][2] = 0; B[5][3] = 0; B[5][4] = -1; B[5][5] = 3;
    
    xb = vetcria(6);
    xb[0] = 0;
    xb[1] = 0;
    xb[2] = 0;
    xb[3] = 0;
    xb[4] = 0;
    xb[5] = 0;
    
    bb = vetcria(6);
    bb[0] = 2.5; bb[1] = 1.5; bb[2] = 1; bb[3] = 1; bb[4] = 1.5; bb[5] = 2.5;
    tol = pow(10., -7);
    
    k = GradConj(6, B, bb, xb, tol);
    printf("\n Numero de iteracoes: %d\n",k);
    vetimprime(6, x, "%.6lf");
    
    
    printf("Gradiente Conjugado com pre-condicionamento\n");
    xb[0] = 0;
    xb[1] = 0;
    xb[2] = 0;
    xb[3] = 0;
    xb[4] = 0;
    xb[5] = 0;
    
    k = GradConjJacobi(6, B, bb, xb, tol);
    printf("\nNumero de iteracoes: %d\n", k);
    vetimprime(6, x, "%.6lf");
    
    
    vetlibera(b);
    matlibera(2, A);
    matlibera(6, B);
    vetlibera(x);
    vetlibera(xb);
    vetlibera(bb);
    
    return 0;
}

