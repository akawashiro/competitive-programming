//AOJ0058
#include <stdio.h>
int main()
{
	while(1){
		double x1,y1,x2,y2,x3,y3,x4,y4,xd1,yd1,xd2,yd2;
		if(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==EOF)
			break;
		xd1=x1-x2,yd1=y1-y2;
		xd2=x3-x4,yd2=y3-y4;
		if(xd1*xd2+yd1*yd2==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

