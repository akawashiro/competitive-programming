#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	double x=0,y=0,d=90.0;
	double a,b;
	while(1)
	{
		scanf("%lf,%lf",&a,&b);
		if(a==0 && b==0)
			break;
		x+=cos(d*M_PI/180.0)*a;
		y+=sin(d*M_PI/180.0)*a;
		d-=b;
	}
	printf("%d\n%d\n",(int)x,(int)y);
	return 0;
}

