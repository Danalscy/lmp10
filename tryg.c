#include "makespl.h"
#include <math.h>
#include <stdlib.h>
void make_spl (points_t * pts, spline_t * spl){
	
	if (alloc_spl(spl, pts->n) == 0) {
        	spl->x = pts->x;
	
		int i,j;
		int n=pts->n;
		int L;
		int nb;
		if(n % 2)
			L=((n-1)/2);
		else
			L=(n/2);
		char *nbEnv= getenv( "APPROX_BASE_SIZE" );
        	if( nbEnv != NULL && atoi( nbEnv ) > 0 && atoi(nbEnv)<(n/2))
                	nb = atoi( nbEnv );
		else
			nb=L-1;

		for( i=0; i<n; i++)
                	spl->a[0]+=(1.0/L)*pts->y[i];
		
		spl->b[0]=0;
		for(j=1;j<=nb;j++){
			spl->a[j]=0.0;
			spl->b[j]=0.0;
			for(i=0;i<n;i++){
				spl->a[j]+=(1.0/L)*pts->y[i]*cos((M_PI*i*j)/L);	
				spl->b[j]+=(1.0/L)*pts->y[i]*sin((M_PI*i*j)/L);
			}
		}
		for(j=0;j<n;j++){
			spl->f[j]=spl->a[0]/2;
			spl->f1[j]=0.0;
			spl->f2[j]=0.0;
			spl->f3[j]=0.0;
			spl->f4[j]=0.0;
			double tmp=spl->x[j];
			for(i=1;i<=nb;i++){
                		spl->f[j]+=spl->a[i]*cos(i * (tmp)) + spl->b[i]*sin(i * (tmp));
                		spl->f1[j]+= -i * spl->a[i]*sin(i*(tmp)) + i *spl->b[i]*cos(i*(tmp));
                		spl->f2[j]+= -i * i *spl->a[i]*cos(i*(tmp)) - i * i * spl->b[i]*sin(i*(tmp));
                		spl->f3[j]+=  i * i * i * spl->a[i]*sin(i*(tmp)) - i * i * i * spl->b[i]*cos(i*(tmp));
				spl->f4[j]+=  i * i * i * i * spl->a[i]*cos(i*(tmp)) + i * i * i * i * spl->b[i]*sin(i*(tmp));
        		}
		}
	}
 }
