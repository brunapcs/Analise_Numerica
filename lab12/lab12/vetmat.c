#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetmat.h"

double * vetcria(int n)
{
	double *v;
	v = (double*) malloc(n*(sizeof(double)));
	if (v == NULL)
	{
		printf("Erro de memoria");
		exit(1);
	}
	return v;
}
void vetlibera(double* v)
{
	free(v);
}
double escalar(int n, double* v, double* w)
{
	double vm=0;
	double wm=0;
	double r;
	int i;

	for(i=0;i<n;i++){
		vm += v[i]*v[i];
	}
	vm = sqrt(vm);

	for(i=0;i<n;i++){
		wm += w[i]*w[i];
	}
	wm = sqrt(wm);
	r = wm*vm;
	return r;
}

double norma2(int n, double* v)
{
	int i;
	double t=0;
	for(i=0;i<n;i++)
	{
		t += v[i]*v[i];
	}
	t = sqrt(t);
	return t;
}

int vetiguais(int n, double* v, double* w, double tol)
{
	int i;
	int r;
	double t;

	for(i=0; i<n; i++)
	{
		t = fabs((v[i] - w[i]));
		if(t <= tol)
		{
			r=1; 
		}
		else
		{
			r=0;
			break;
		}
	}
	if(r==0)
	{
		printf("Vetores diferentes\n");
		return 0;
	}
	else
	{
		printf("Vetores iguais\n");
		return 1;
	}

}

void vetimprime(int n, double* v, char* format)
{
	int i;

	for(i=0; i<n; i++)
	{
		printf(format, v[i]);
		printf("\n");
	}
}

double** matcria(int m, int n)
{
	double** A;
	int i;

	A = (double**) malloc(m*sizeof(double*));
	if (A == NULL)
	{
		printf("Erro de memoria");
		exit(1);
	}

	for(i=0;i<m;i++)
	{
		A[i] = (double*) malloc(n*sizeof(double));
		if (A[i] == NULL)
		{
		printf("Erro de memoria");
		exit(1);
		}
	}
	return A;
}

void matlibera(int m, double** A)
{
	int i;
	for(i=0;i<m;i++){
		free(A[i]);
	}
	free(A);
}

void transposta(int m, int n, double** A, double**T)
{
	int i, j;

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			T[j][i] = A[i][j];
		}
	}
}

void multmv(int m, int n, double** A, double* v, double* w)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        w[i] = 0;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        w[i] += A[i][j]*v[j];
        }
    }
   // vetimprime(m, w, "%.2f");
}

void multmm(int m, int n, int q, double** A, double** B, double** C)
{
    int i, j, k;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
        C[i][j] = 0;
        }
    }
    for(i=0; i<m; i++)
    {
        for(k=0; k<n; k++)
        {
            for(j=0; j<n; j++)
            {
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
    matimprime(n, q, C, "%.2f");
}

int matiguais(int m, int n, double** A, double** B,double TOL)
{
	int i,j;
	int r;

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		
			if(fabs(A[i][j] - B[i][j]) <= TOL)
			{
				r = 1;
			}
			else
			{
				r = 0;
				break;
			}
		}
		if(r==0)
		{
			break;
		}
	}
	
	if(r==0)
	{
		printf("Matrizes diferentes\n");
		return 0;
	}
	else
	{
		printf("Matrizes iguais\n");
		return 1;
	}

}

void matimprime(int m, int n, double** A, char* format)
{
	int i, j;

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf(format, A[i][j]);
			printf("  ");
		}
		printf("\n");
	}
}
