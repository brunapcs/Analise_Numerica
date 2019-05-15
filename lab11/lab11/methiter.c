#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "methiter.h"
#include "vetmat.h"

//funcao auxiliar
static double norma2_diff (int n, double* v, double* w){

	double soma2 = 0;
	int i = 0;
	for (i=0; i<n; i++)
		soma2 += (v[i] - w[i]) * (v[i] - w[i]);

	return sqrt(soma2);
}

int Jacobi (int n, double** A, double* b, double* x, double tol){
	int it;
	int norma = 1;
	int i, j;
	double* ult = vetcria(n);

	for (it = 1; norma > tol; it++){
        for(i = 0; i < n; i++)
            ult[i] = x[i];

		for (i = 0; i < n; i++){
			double lu_xk = 0;
			for (j = 0; j < n ; j++){
				if (i != j){
					lu_xk += A[i][j] * ult[j];
				}
			}
			x[i] = (b[i] - lu_xk) / A[i][i];
		}
		norma = norma2_diff(n, ult, x);
	}

	free (ult);
	return it;

}

int GaussSeidel (int n, double** A, double* b, double* x, double tol){
	int it;
	int norma = 1;
	int i, j;
	double* ult = vetcria(n);

	for (it = 1; norma > tol; it++){
        for(i = 0; i < n; i++)
            ult[i] = x[i];

		for (i = 0; i < n; i++){
			double lu_xk = 0;
			for (j = 0; j < n ; j++){
				if (i != j){
					lu_xk += A[i][j] * x[j];
				}
			}
			x[i] = (b[i] - lu_xk) / A[i][i];
		}
		norma = norma2_diff(n, ult, x);
	}
	free (ult);
	return it;
}


int SOR (int n, double** A, double* b, double* x, double tol, double w){
	int it;
	int norma = 1;
	int i, j;
	double* ult = vetcria(n);

	for (it = 1; norma > tol; it++){
        for(i = 0; i < n; i++)
            ult[i] = x[i];

		for (i = 0; i < n; i++){
			double lu_xk = 0;
			for (j = 0; j < n ; j++){
				if (i != j){
					lu_xk += A[i][j] * x[j];
				}
			}
			x[i] = (b[i] - lu_xk) / A[i][i];
			x[i] = (1-w)*ult[i] + w*x[i];
		}
		norma = norma2_diff(n, ult, x);
	}
	free (ult);
	return it;

}
