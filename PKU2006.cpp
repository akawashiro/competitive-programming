#include <stdio.h>
#include <math.h>

int main()
{
	double K,A;
	int n,m;
	while(scanf("%lf%lf%d%d",&K,&A,&m,&n),n||m)
	{
		double a=(double)n/(double)m;
		double b=1.0/(double)m*K;
		double c=-A*K;
		//printf("a=%lf b=%lf c=%lf\n",a,b,c);
		double ans=-log10((-b+sqrt(b*b-4*a*c))/(2*a));
		printf("%.3lf\n",ans);
	}
	return 0;
}

