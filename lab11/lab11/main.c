#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "methiter.h"
#include "vetmat.h"

int main(void){
	int iter;
	double tol;
	double *xa, *ba, *xb, *bb;
	double **A, **B;

	A = matcria(2, 2);
	A[0][0] =  3; A[0][1] = 1;
	A[1][0] =  1; A[1][1] = 2;
	printf("    MATRIZ A\n");
	matimprime(2, 2, A, "%.2f");

	xa = vetcria(2);
	xa[0] = 0; xa[1] = 0;

	ba = vetcria(2);
	ba[0] = 5; ba[1] = 5;

	

	B = matcria(6, 6);
	B[0][0] =  3; B[0][1] = -1; B[0][2] = 0; B[0][3] = 0; B[0][4] = 0; B[0][5] = 0.5;
	B[1][0] =  -1; B[1][1] = 3; B[1][2] = -1; B[1][3] = 0; B[1][4] = 0.5; B[1][5] = 0;
	B[2][0] =  0; B[2][1] = -1; B[2][2] = 3; B[2][3] = -1; B[2][4] = 0; B[2][5] = 0;
	B[3][0] =  0; B[3][1] = 0; B[3][2] = -1; B[3][3] = 3; B[3][4] = -1; B[3][5] = 0;
	B[4][0] =  0; B[4][1] = 0.5; B[4][2] = 0; B[4][3] = -1; B[4][4] = 3; B[4][5] = -1;
	B[5][0] =  0.5; B[5][1] = 0; B[5][2] = 0; B[5][3] = 0; B[5][4] = -1; B[5][5] = 3;	
	printf("\n      MATRIZ B:\n");
	matimprime(6, 6, B, "%.2f");

	xb = vetcria(6);
	xb[0] =  0; xb[1] = 0; xb[2] = 0; xb[3] = 0; xb[4] = 0; xb[5] = 0;

	bb = vetcria(6);
	bb[0] =  2.5; bb[1] = 1.5; bb[2] = 1; bb[3] = 1; bb[4] = 1.5; bb[5] = 2.5;
	


	tol = pow(10., -7);
	
    printf("\n RESPOSTAS : \n");
	printf("\n*******  MATRIZ A ********");
	printf("\n Jacobi \n");
	iter = Jacobi(2, A, ba, xa, tol);
	vetimprime(2, xa, "%.7f");
	printf("iteracoes: %d\n", iter);

	printf("\nGauss-Seidel--\n");
	xa[0] = 0; xa[1] = 0;
	iter = GaussSeidel(2, A, ba, xa, tol);
	vetimprime(2, xa, "%.7f");
	printf(" iteracoes: %d\n", iter);


	printf("\n Gauss-Seidel com sobre-relaxamento\n");
    xa[0] = 0; xa[1] = 0;
	iter = SOR(2, A, ba, xa, tol, 1.1);
	vetimprime(2, xa, "%.7f");
	printf("iteracoes: %d\n", iter);


	printf("\n ******** MATRIZ B *******");

	printf("\nJacobi\n");
	iter = Jacobi(6, B, bb, xb, tol);
	vetimprime(6, xb, "%.7f");
	printf("iteracoes: %d\n", iter);

	printf("\nGauss-Seidel\n");

	xb[0] =  0; xb[1] = 0; xb[2] = 0; xb[3] = 0; xb[4] = 0; xb[5] = 0;
	iter = GaussSeidel(6, B, bb, xb, tol);
	vetimprime(6, xb, "%.7f");

	printf("iteracoes: %d\n", iter);
	printf("\n Gauss-Seidel com sobre-relaxamento\n");
	
	xb[0] =  0; xb[1] = 0; xb[2] = 0; xb[3] = 0; xb[4] = 0; xb[5] = 0;	
	iter = SOR(6, B, bb, xb, tol, 1.1);
	vetimprime(6, xb, "%.7f");
	printf("iteracoes: %d\n", iter);


	matlibera(2, A);
	matlibera(6, B);
	vetlibera(xa);
	vetlibera(xb);
	vetlibera(ba);
	vetlibera(bb);

	return 0;
}
