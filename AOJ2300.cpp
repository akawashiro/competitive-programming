//AOJ2300
#include <stdio.h>
#include <limits.h>
double sq(double d){	return d*d;	}

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<31;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

int main(){
	int n,m;
	double l[20],a[20],b[20];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lf%lf%lf",l+i,a+i,b+i);
	double ans=0;
	for(int s=0;s<(1<<n);s++)
		if(popCount(s)==m){
			double d=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(((1<<i)&s)&&((1<<j)&s))
						d+=sq(l[i]-l[j])+sq(a[i]-a[j])+sq(b[i]-b[j]);
			if(ans<d)
				ans=d;
		}
	printf("%lf\n",ans);
}

