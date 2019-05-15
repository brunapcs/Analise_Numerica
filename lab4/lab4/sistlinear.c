#include "sistlinear.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>


void vetimprime (int n, double* v, char* format){
    int i = 0;
    for (i=0; i<n; i++){
        printf(format, v[i]);
        printf("\n");
    }
}

void vetlibera (double* v){
    free (v);
}

void matimprime(int m, int n, double** A, char* format) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf(format, A[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("--------------------\n");
}

double** matcria (int m, int n){
    int i;
    double** mat = (double**) malloc(sizeof(double*)*m);
    
    for (i = 0; i < m; i++)
        mat[i] = (double*)malloc(sizeof(double)*n);
    return mat;
}

void matlibera(int m, double** A) {
    int i;
    for (i = 0; i < m; i++)
        free(A[i]);
    free(A);
}


int* fatoracao (int n, double** A){
    double pivo, aux, mult;
    int r;
    //aloca e inicializa vetor p
    int *p = (int *)malloc(n*sizeof(int));
    if(p== NULL)
        exit(0);
    //inicializacao de p
    for(int i=0; i<n; i++)
        p[i] = i;
    

    for(int k= 0; k<n-1 ; k++){
        pivo = fabs(A[k][k]);
        r=k;
        //pivotamento
        for(int i= k+1; i<n; i++){
            if(fabs(A[i][k])>pivo){
                pivo= fabs(A[i][k]);
                r=i ;
            }
        }
        //se pivo = 0 parar, a matriz A eh singular
     //   if(pivo == 0 )
       //   break;
        
        
        if (r != k ){
            //se troca for ser realizada organiza vetor p
            aux= p[k];
            p[k] = p[r];
            p[r] = aux;
            //troca de linhas
            for(int j= 0; j<n ; j++){
                aux = A[k][j];
                A[k][j] = A[r][j];
                A[r][j] = aux;
                
            }
        }
        //gauss
        for(int i = k+1; i<n; i++){
            mult = A[i][k]/A[k][k];
            A[i][k] = mult;
            for(int j=k+1; j<n ; j++ )
                A[i][j]= A[i][j] - mult*A[k][j];
        }
    }
        return p;
}

double* substituicao (int n, double** A, int* p, double* b){
    int temp;
    double sum;
    
    double *x= (double *)malloc(n *sizeof(double));
    if(x == NULL)
        exit(0);
    
    double *aux= (double *)malloc(n *sizeof(double));
    double *y =  (double *)malloc(n *sizeof(double));

  
    
    for(int i =0; i<n; i++){
        temp = p[i];
        aux[i] = b[temp];
    }
    
    for(int i=0; i<n; i++){
        sum =0;
        for(int j=0; j<i; j++)
            sum = sum + A[i][j]*y[j];
        y[i]= aux[i] - sum;
    }
    for(int i=0; i<n; i++)
        printf("%lf\n", y[i]);
    
    for(int i=n-1; i>=0; i--){
        sum= 0;
        for(int j= i+1; j<n ; j++)
            sum = sum + A[i][j]*j;
        x[i]= (y[i]-sum)/A[i][i];
    }
    
    free(aux);
    free(y);
    return x;
}
    
    
    
    
    
    


