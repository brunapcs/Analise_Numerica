#include <stdio.h>
#include <math.h>
#include "integral.h"

double derivada(double (*f) (double x), double x, double h)
{
	return ((f(x+h) - f(x-h))/(2*h));
}
double h_otimo (double (*f) (double x), double (*fl) (double x), double x) //O x a ser passado deve equivaler a c??
{
	double h, hf, i, e, er, fn, fa;
	e = 100000000;
	er = 0;
	hf = 0;
	for(i = 1; i < 13; i++)
	{
		h = pow(10, -i);
		fn =  derivada(f, x, h);
		fa = fn - ((pow(h, 2)/6) * derivada(fl, x, h));
		er = fabs(fa - fn);
		if(e > er)
		{
			e = er;
			hf= h;
		}
	}
	return hf;
}
double simpson (double (*f) (double), double a, double b, int n)
{
	int i;
	double h, ic, ax;
	h = (b - a)/n;
	ic = 0;
	ax = a;
	for(i=0; i <= n; i++)
	{
		ic += (h/6)*(f(ax) + 4*f(ax+(h/2)) + f(ax+h));
		ax += h;
	}
	ax -= h;
	return ic;
}
double pontomedio (double (*f) (double), double a, double b, int n)
{
	int i;
	double h, ic, w, ax;
	h = (b - a)/n;
	ic = 0;
	ax = a;
	for(i=0; i <= n; i++)
	{
		w = (ax + (ax + h))/2;
		ic += (h)*(f(w));
		ax += h;
	}
	return ic;
}