//
//  integral.h
//  lab7
//
//  Created by Bruna Paracat  on 5/11/18.
//  Copyright © 2018 Bruna Paracat. All rights reserved.
//

#ifndef integral_h
#define integral_h

double f(double x); 
double analitica(double x);
double f1(double x);
double f2(double x);
double f3(double x);
double derivada(double(*f)(double x), double x , double h);
double h_otimo(double(*f)(double x), double(*f1)(double x), double x);
double simpson(double (*f)(double x), double a, double b, int n);
double pontomedio (double (*f) (double), double a, double b, int n);


#endif /* integral_h */
