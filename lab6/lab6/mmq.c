#include<stdio.h> 
#include<stdlib.h> 
#include "Lab0.h" 
#include "mmq.h" 
#include <math.h> 
#include "sistlinear.h" 

double* mmq(int m, int n, double **A, double *b){ 
	double **T  = matcria(n,m);
	double **C = matcria(m,m); 
	double *w = vetcria(n); 
	int *p;
	double *v; 

	transposta( m,  n, A, T); //faz matriz T ser transposta de A  
	multmm(n,m, m, T,A, C); // multiplica A pela transposta e salva em C
	multmv(n, m, T, b, w); //multiplica T pelo vetor b salva em w
	p = fatoracao(n,C); //fatora matriz C em LU
	v= substituicao (n , C , p, w); // resolve sistema Cx = w
    
	vetLibera(w);
	matlibera(n,C);
    matlibera(n,T);
	return v;
} 

double Norma2( int m, int n, double **A, double *b, double *x){ 
	int i;
	double soma = 0; 
	double *w= vetcria(m);
	double *r=vetcria(m); 
	multmv(m ,n, A, x, w); // multiplica A*x salva em w[5]
    
	for(i=0; i<m; i++)  //r = b - w 
		r[i] = b[i] - w[i]; 

	for(i=0; i<m; i++) //somatorio de r^2
		soma+= pow(2, r[i]); 

	soma = sqrt(soma); 

	vetLibera(w); 
	vetLibera(r); 
	return soma; 
}

double concentracao (int n, double* t, double* c, double* pa, double* pb){
    double **A= matcria(n, 2);
    double *x;
    double *b = vetcria(n);
    int i , j ;
    double soma = 0;
    double *r=vetcria(n);
    
    for(i=0; i<n; i++){
        for(j=0; j<2; j++){
            if(j==0)
                A[i][j] = 1;
            else
                A[i][j] = t[i]+1;
        }
    }
    for(i = 0; i<n ;i++ )
        b[i] = log(c[i]/(t[i]+1));
    
    x = mmq(n,2,A,b);
    *pa = exp(x[0]);
    *pb = x[1];
    
    //NORMA2
    for(i=0; i<n; i++)  //r = b - w
        r[i] = log(c[i]/(t[i]+1)) - log(*pa) - (*pb * (t[i]+1));
    
    for(i=0; i<n; i++) //somatorio de r^2
        soma+= pow(2, r[i]);
    soma = sqrt(soma);
    

    vetLibera(r); 
    return soma;
}



