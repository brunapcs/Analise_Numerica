#include<stdio.h> 
#include<stdlib.h> 
#include "Lab0.h" 
#include "mmq.h" 
#include "sistlinear.h" 


int main(){ 
	int m = 5, n = 3, i;
	double **A =matcria(m ,n);  
	double *x =vetcria(n); 
	double *b =vetcria(m); 
	double norma, a , pb;
    double *t = vetcria(8);
    double *c = vetcria(8);
    
    
	
   
	A[0][0] = 3;  A[0][1] = -1; A[0][2] = 2;
    A[1][0] = 4;  A[1][1] = 1;  A[1][2] = 0;
    A[2][0] = -3; A[2][1] = 2; A[2][2] = 1;
    A[3][0] = 1;  A[3][1] = 1; A[3][2] = 5;
	A[4][0] = -2; A[4][1] = 0; A[4][2] = 3;

	b[0]=10;b[1]=10;b[2]=-5;
	b[3]=15;b[4]=0;b[0]=10;

	x = mmq( m,  n, A, b);
    norma = Norma2(m,  n, A,  b, x);

    printf("***********Primeiro problema ***********\n");
	for(i=0; i<n; i++){
		printf("%lf\n", x[i]);
	}
    printf("NORMA: %lf\n" ,norma);
    
    vetLibera(x);
    matlibera(m,A);
    vetLibera(b);
    
    n = 4;
    A =matcria(m ,n);
    x =vetcria(n);
    b =vetcria(m);

    
    A[0][0] = 4;  A[0][1] = 2; A[0][2] = 3;  A[0][3]=0;
    A[1][0] = -2; A[1][1] = 3; A[1][2] = -1; A[1][3]=1;
    A[2][0] = 1;  A[2][1] = 3; A[2][2] = -4; A[2][3]=2;
    A[3][0] = 1;  A[3][1] = 0; A[3][2] = 1;  A[3][3]=-1;
    A[4][0] = 3;  A[4][1] = 1; A[4][2] = 3;  A[4][3]=-2;
    
    b[0]=10;b[1]=0;b[2]=2;
    b[3]=0;b[4]=5;
    
    x = mmq( m,  n, A, b);
    norma = Norma2(m,  n, A,  b, x);
    
    printf("\n***********Segundo problema ***********\n");
    for(i=0; i<n; i++){
        printf("%lf\n", x[i]);
    }
    printf("NORMA: %lf\n" ,norma);
	matlibera(m,A); 
	vetLibera(x); 
	vetLibera(b);
    
    
    printf("\n***********Terceiro problema ***********");
    for(i=1; i<=8; i++)
        t[i]= i;
    
    c[0] = 8;
    c[1] = 12.3;
    c[2] = 15.5;
    c[3] = 16.8;
    c[4] = 17.1;
    c[5] = 15.8;
    c[6] = 15.2;
    c[7] = 14;
    
    
   norma =  concentracao ( 8, t,c, &a, &pb);
    printf("\n a: %.2lf \n ", a);
    printf("b: %.2lf \n ", pb);
    printf("Norma2: %.2lf\n" , norma);
    
    printf("a"); 
    vetLibera(t);
    vetLibera(c);
	return 0; 
} 
