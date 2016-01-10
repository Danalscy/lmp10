#include "splines.h"
#include <math.h>
#include <stdlib.h>

#define MALLOC_FAILED( P, SIZE ) (((P)=malloc( (SIZE)*sizeof( *(P))))==NULL)

int alloc_spl (spline_t * spl, int n){
  	spl->n = n;
  	return MALLOC_FAILED (spl->x, spl->n)
    	|| MALLOC_FAILED (spl->y, spl->n)
    	|| MALLOC_FAILED (spl->a, spl->n)
    	|| MALLOC_FAILED (spl->b, spl->n);
}

int read_spl (FILE * inf, spline_t * spl){
	int i;
  	if (fscanf (inf, "%d", &(spl->n)) != 1 || spl->n < 0)
    		return 1;

  	if (alloc_spl (spl, spl->n))
    		return 1;

  	for (i = 0; i < spl->n; i++)
   		if (fscanf(inf, "%lf %lf %lf %lf", spl->x + i, spl->y + i, spl->a + i, spl->b + i) != 4)
      		return 1;

  return 0;
}

void write_spl (spline_t * spl, FILE * ouf){
  	int i;
  	fprintf (ouf, "%d\n", spl->n);
  	for (i = 0; i < spl->n; i++)
  	fprintf (ouf, "%g %g %g %g\n", spl->x[i], spl->y[i], spl->a[i], spl->b[i]);
}

double value_spl (spline_t * spl, double x){
	int i;
	int m;
  	double suma=spl->a[0];
	if((spl->n) % 2)
		m=((spl->n-1)/2)-1;
	else
		m=(spl->n-1)/2;
	for(i=1;i<=m;i++)
		suma+=spl->a[i]*cos((2.0*M_PI*i*x)/spl->n) + spl->b[i]*sin((2.0*M_PI*i*x)/spl->n);

	return suma;
 } 
