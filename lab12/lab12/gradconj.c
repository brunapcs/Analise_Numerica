#include "gradconj.h"
#include "vetmat.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static double *vetdiff(double *v1 , double *v2, int n){
    double *v= vetcria(n);
    for(int i=0; i<n; i++)
        v[i]= v1[i]-v2[i];
    return v;
}
static void vetcopia(double *v1, double *v2, int n){
    for(int i=0; i<n; i++)
        v2[i]= v1[i];
}


static void diagonal(double **A, double **D, int m, int n){
    for(int i=0; i<m;i++ ){
        for(int j=0; j<n ;j ++){
            if(j == i)
                D[i][j] = 1/A[i][j];
            else
                D[i][j] = 0;
        }}
}

int GradConj (int n, double** A, double* b, double* x, double tol){
    double *v = vetcria(n);
    double *r = vetcria(n);
    double *d = vetcria(n);
    double *Ad = vetcria(n);
    double *aux2 = vetcria(n);
    double alpha=0, beta = 0, auxAlpha=0, div=0, aux3=0;
    int k=0;
    
    multmv(n, n, A , x , v);
    r = vetdiff(b, v , n); // r = b -Ax
    vetcopia(r, d, n);
    
    tol = 0.0000001;
    
    
    while(norma2(n, r )> tol){
        k++;
        multmv(n, n, A, d , Ad); // Ad = A*d
        
        //rT*r
        for(int i=0;i< n; i++)
            auxAlpha+=r[i]*r[i];
        //dT* Ad
        for(int i=0; i<n; i++)
            div +=d[i]*Ad[i];
        
        alpha= auxAlpha/div;
        
        //alpha*d
        for(int i=0; i<n; i++)
            aux2[i]= d[i]*alpha;
        // x1 = x + alpha*d
        for(int i=0; i<n;i++)
            x[i] = x[i] + aux2[i];
        //
        for(int i=0; i<n; i++)
            aux2[i]= Ad[i]*alpha;
        //
        for(int i=0; i<n;i++)
            r[i] = r[i] - aux2[i];
        //rT*r
        for(int i=0;i<n;i++)
            aux3 +=r[i]*r[i];
        
        beta = aux3/ auxAlpha;
        
        //B*d
        for(int i=0; i<n; i++)
            aux2[i]= d[i]*beta;
        
        for(int i=0; i<n;i++)
            d[i] = r[i] + aux2[i];
    }
    
    vetlibera(v);
    vetlibera(r);
    vetlibera(d);
    vetlibera(Ad);
    vetlibera(aux2);
    return k;
}

int GradConjJacobi (int n, double** A, double* b, double* x, double tol){
    double **D= matcria(n, n);
    diagonal(A, D, n, n);
    double *v = vetcria(n);
    double *r = vetcria(n);
    double *d = vetcria(n);
    double *z = vetcria(n);
    double *Ad = vetcria(n);
    double *aux2 = vetcria(n);
    double alpha=0, beta = 0, auxAlpha=0, div=0, aux3=0;
    int k=0;
    
    // r = b -Ax
    multmv(n, n, A , x , v);
    r = vetdiff(b, v , n);
    
    //d = z0 = M*r0
    multmv(n, n,D, r, d);
    vetcopia(d, z, n);
    
    while(norma2(n, r )>tol){
        k++;
        multmv(n, n, A, d , Ad); // Ad = A*d
        
        //rT*z
        for(int i=0;i< n; i++)
            auxAlpha+=r[i]*z[i];
        //dT* Ad
        for(int i=0; i<n; i++)
            div +=d[i]*Ad[i];
        alpha= auxAlpha/div;
        
        //alpha*d
        for(int i=0; i<n; i++)
            aux2[i]= d[i]*alpha;
        // x1 = x + alpha*d
        for(int i=0; i<n;i++)
            x[i] = x[i] + aux2[i];
        // alpha*Ad
        for(int i=0; i<n; i++)
            aux2[i]= Ad[i]*alpha;
        // r = r - Alpha*Ad
        for(int i=0; i<n;i++)
            r[i] = r[i] - aux2[i];
        //z =M*r
        multmv(n, n, D, r, z );
        
        //rT*r
        for(int i=0;i<n;i++)
            aux3 +=r[i]*z[i];
        beta = aux3/auxAlpha;
        
        //B*d
        for(int i=0; i<n; i++)
            aux2[i]= d[i]*beta;
        
        for(int i=0; i<n;i++)
            d[i] = z[i] + aux2[i];
    }
    vetlibera(v);
    vetlibera(r);
    vetlibera(d);
    vetlibera(Ad);
    vetlibera(aux2);
    vetlibera(z);
    for(int i =0; i<n ; i++){
        free(D[i]);
    }
    free(D);
    return k;
}

















