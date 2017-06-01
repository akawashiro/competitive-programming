//AOJ0073
#include <stdio.h>
#include <math.h>
int main()
{
	while(1){
		double x,h;
		scanf("%lf%lf",&x,&h);
		if(x==0&&h==0)
			break;
		printf("%lf\n",x*x+x*sqrt(x*x/4+h*h)*2);
	}
	return 0;
}

