#include "oldsplines.h"
#include "points.h"
#include <math.h>
void make_spl (points_t * pts, spline_t * spl){

	if (alloc_spl(spl, pts->n) == 0) {
        	spl->x = pts->x;
        	spl->y = pts->y;
	
		int i,j;
		int n=pts->n;
		int L;
		if(n % 2)
			L=((n-1)/2);
		else
			L=(n/2);
		int st=L-1;
		for( i=0; i<n; i++)
                spl->a[0]+=(1.0/L)*pts->y[i];
		spl->b[0]=0;

		for(j=1;j<=st;j++){
		spl->a[j]=0.0;
		spl->b[j]=0.0;
			for(i=0;i<n;i++){
				spl->a[j]+=(1.0/L)*spl->y[i]*cos((M_PI*i*j)/L);	
				spl->b[j]+=(1.0/L)*spl->y[i]*sin((M_PI*i*j)/L);
			}
		}
		
	}	
}
