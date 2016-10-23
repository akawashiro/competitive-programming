//AOJ1100
#include <stdio.h>
#include <math.h>
double heron(double x1,double y1,double x2,double y2,double x3,double y3){
	double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	double c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	double s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double cross(double x1,double y1,double x2,double y2,double x3,double y3){
	double a1=x2-x1;
	double b1=y2-y1;
	double a2=x3-x1;
	double b2=y3-y1;
	return a1*b2-a2*b1;
}
int main(){
	for(int t=1;;t++){
		int n;
		double x[50],y[50];
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		double S=0;
		for(int i=1;i<n-1;i++)
			S+=cross(x[0],y[0],x[i],y[i],x[i+1],y[i+1]);
		S/=2;
		if(S<0)
			S=-S;
		printf("%d %.1lf\n",t,S);
	}
	return 0;
}

