#include <cmath>
#include <cstdio>
#include <algorithm>

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		double xa,ya,ra,xb,yb,rb,d;
		scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&ra,&xb,&yb,&rb);
		d=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));

		if(ra+rb<d)
			printf("0\n");
		else if(ra<rb && d<rb-ra)
			printf("-2\n");
		else if(rb<ra && d<ra-rb)
			printf("2\n");
		else
			printf("1\n");
	}

	return 0;
}

