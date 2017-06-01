//AOJ0079
#include <stdio.h>
#include <math.h>
double heron(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	double c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	double s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main()
{
	int n=0;
	double x[20],y[20];
	while(1){
		if(scanf("%lf,%lf",x+n,y+n)==EOF)
			break;
		n++;
	}
	double S=0;
	for(int i=0;i<n-2;i++)
		S+=heron(x[i],y[i],x[i+1],y[i+1],x[n-1],y[n-1]);
	printf("%lf\n",S);
	return 0;
}


