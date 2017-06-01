//AOJ0135
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d",&n);
	for(;0<n;n--){
		int hh,mm;
		double h,m;
		scanf("%d:%d",&hh,&mm);
		h=30*hh+(double)mm/2;
		m=mm*6;
		double d=fabs(h-m);
		if(180<d)
			d=360-d;
		//printf("d=%lf\n",d);
		if(d<30)
			printf("alert\n");
		else if(90<=d)
			printf("safe\n");
		else
			printf("warning\n");
	}
	return 0;
}

