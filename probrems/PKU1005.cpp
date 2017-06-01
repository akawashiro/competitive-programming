#include <cmath>
#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);

	for(int time=0;time<n;time++)
	{
		int year=1;
		double x,y;

		scanf("%lf%lf",&x,&y);
		year=1+floor((x*x+y*y)*3.141592/2.0/50.0);

		printf("Property %d: This property will begin eroding in year %d.\n",time+1,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}

