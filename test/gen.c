#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
double fun( double x ) {double r= ((double)rand() - RAND_MAX/2.0)/RAND_MAX/5;
	//return (1+r)*(sin(x)-cos(3*x));				
	return (1+r)*(sin(x));				
}

int main( int argc, char **argv ) {
				int n= argc > 1 ? atoi( argv[1] ) : 100;
				FILE *out= argc > 2 ? fopen( argv[2], "w" ) : stdout;

				int a=0;
				int i;
				double dx =2*M_PI/n;

				for( i =0; i < n; i++ ) {
								fprintf( out, "%g %g\n", a+i*dx, fun(a+i*dx) );
				}
				fclose( out );

				return 0;
}
