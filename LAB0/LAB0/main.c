#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1
double *vetcria(int n){
    
    double *vet = (double*)malloc(n*(sizeof(double)));
    if (vet == NULL)
        exit (0);
    else
        return vet;
}

//2
void vetLibera(double *v){
    free(v);
}
//3
double escalar(int n, double *v, double *w){
    double soma= 0;
    for(int i=0; i<n; i++){
        soma += v[i] * w[i];
    }
    return soma;
}

//4
double norma2(int n, double *v){
    double soma=0;
    for(int i=0; i<n; i++){
        soma+=(v[i]*v[i]);
    }
    return sqrt(soma);
}
//5
int vetiguais(int n, double *v, double *w, double tol){
    for(int i=0; i<n; i++){
        if(fabs(v[i]-w[i])>tol)
            return 0;
    }
    return 1;
}

//6
void vetimprime(int n, double *v, char *format){
    for(int i=0; i<n; i++){
        printf( format,  v[i]);
        printf("\n");
    }
    
}

//7
double **matcria(int m, int n){
    double  **mat= (double**)malloc(m*sizeof(double));
    if(mat==NULL)
        exit(0);
    for(int i=0; i<m; i++){
        mat[i] = (double*)malloc(n*sizeof(double));
    }
    return mat;
}

//8
void matlibera(int m, double **A)
{
    for(int i=0; i< m; i++)
        free(A[i]);
    free(A);
}

//9
void transposta(int m, int n, double **A, double **T){
    for (int j=0; j< n; j++){
        for(int i=0; i<m; i++)
            T[j][i] = A[i][j];
    }
}

//10
void multmv(int m, int n, double **A, double *v, double *w){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            w[m] += v[j]*A[i][j];
        }
    }
}

//11
void multmm(int m, int n, int q, double **A, double **B, double **C){
    double sum=0;
    for(int i =0; i< m; i++){
        for(int j =0; j<q; j++){
            sum = 0;
            for(int k = 0; k<n ; k++)
                sum+=A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    }
}



//12
int matiguais(int m, int n, double **A, double **B, double tol){
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            if(fabs(A[i][j]-B[i][j])>tol)
                return 0;
        }
    }
    return 1;
}

//13
void matimprime(int m, int n, double **A, char *format){
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            printf(format,  A[i][j], " ");
        }
        printf("\n");
    }
}




int main(){
    double **m;
    m = matcria(5, 10);
    
    for(int i=0; i<5; i++)
        for(int j=0; j<10; j++){
            m[i][j]= j;
        }
    

    return 0;
}
