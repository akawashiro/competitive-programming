#include <stdio.h>

typedef long long LL;

LL gcd(LL x,LL y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

LL lcm(LL x,LL y)
{
	return x*y/gcd(x,y);
}

int main()
{
	while(1){
		int n;
		LL d[10],v[10],r[10];
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			scanf("%lld%lld",d+i,v+i);
		r[0]=1;
		for(int i=0;i<n-1;i++){
			LL a,b,c;
			a=v[i]*d[i+1];
			b=v[i+1]*d[i];
			c=gcd(a,b);
			a/=c,b/=c;
			c=lcm(a,r[i])/r[i];
			for(int j=0;j<=i;j++)
				r[j]*=c;
			r[i+1]=r[i]/a*b;
		}
		for(int i=0;i<n;i++)
			printf("%lld\n",r[i]);
	}
	return 0;
}

