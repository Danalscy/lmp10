#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double fun( double x ) {double r= ((double)rand() - RAND_MAX/2.0)/RAND_MAX/5;
		//return (1+r)*(sin(x)-cos(x));				
		//return (1+r)*(sin(x));
		//return (1+r)*tan(x);
		return (1+r)*(-x *x-tan(x)*3);				
}

int main( int argc, char **argv ) {
	int n= argc > 1 ? atoi( argv[1] ) : 10;
	FILE *out= argc > 2 ? fopen( argv[2], "w" ) : stdout;

	int i;
	double dx =2*M_PI/n;

	for( i =0; i < n; i++ ) {
		fprintf( out, "%g %g\n", i*dx, fun(i*dx) );
	}
	fclose( out );

	return 0;
}
