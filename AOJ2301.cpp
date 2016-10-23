//AOJ2301
#include <stdio.h>
double p,e,t;
double rec(int k,double r,double l)
{
	//printf("k=%d r=%lf l=%lf\n",k,r,l);
	double m=(r+l)/2;
	if(t-e<=r&&l<=t+e)
		return 1;
	if(l<t-e||t+e<r)
		return 0;
	if(k==0)
		return (t-e<=m&&m<=t+e);
	if(m<t)
		return rec(k-1,m,l)*(1-p)+rec(k-1,r,m)*p;
	else
		return rec(k-1,r,m)*(1-p)+rec(k-1,m,l)*p;
}
int main()
{
	int K;
	double R,L;
	scanf("%d%lf%lf%lf%lf%lf",&K,&R,&L,&p,&e,&t);
	printf("%lf\n",rec(K,R,L));
	return 0;
}

