#include "makespl.h"
#include <math.h>
void make_spl (points_t * pts, spline_t * spl){
	
	if (alloc_spl(spl, pts->n) == 0) {
        	spl->x = pts->x;
        	spl->y = pts->y;
	
		int i,j;
		int m=0;
		int n=pts->n;
		if(n % 2)
			m=((n-1)/2)-1;
		else
			m=(n-1)/2;
		for(j=1;j<=n;j++)
			spl->a[0]+=spl->y[j-1]/n;
		
		for(i=1;i<m;i++){
			for(j=0;j<n;j++){
				spl->a[i]+=(2.0/n)*spl->y[j]*cos((2.0*M_PI*i*j)/n);	
				spl->b[i]+=(2.0/n)*spl->y[j]*sin((2.0*M_PI*i*j)/n);
			}
		}
	}
 }
