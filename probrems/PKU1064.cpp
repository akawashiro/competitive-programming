#include <vector>
#include <stdio.h>
#include <math.h>
#include <float.h>

using namespace std;

int n,k;
vector<double> cable;

int C(double l)
{
	int r=0;
	for(int i=0;i<n;i++)
		r+=(int)(cable[i]/l);
	return k<=r;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		double a;
		scanf("%lf",&a);
		cable.push_back(a);
	}
	double c=100*1000*1000,b=0.0;
	for(int i=0;i<200;i++)
	{
		double m=(c+b)/2;
		if(C(m))
			b=m;
		else
			c=m;
	}
	printf("%.2lf\n",floor(c*100)/100);
	return 0;
}

