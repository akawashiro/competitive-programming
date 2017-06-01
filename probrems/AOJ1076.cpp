#include <stdio.h>
#include <math.h>

typedef long long LL;

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<31;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

LL gcd(LL x,LL y)
{
	if(y==0)
		return x;
	else
		return gcd(y,x%y);
}

LL lcm(LL x,LL y)
{
	return x/gcd(x,y)*y;
}

int main()
{
	while(1)
	{
		int n,m;
		double sum,ans;
		LL num;
		LL p[20];
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		for(int i=0;i<m;i++)
			scanf("%lld",p+i);
		num=0;
		sum=0;
		for(int on=0;on<1<<m;on++){
			LL a=1;
			double b;
			for(int i=0;i<m;i++)
				if(on & 1<<i)
					a=lcm(a,p[i]);
			b=(LL)n/a;
			if(popCount(on)%2==1){
				num-=b;
				sum-=b*(a+a*b)/2.0;
			}else{
				num+=b;
				sum+=b*(a+a*b)/2.0;
			}
			//printf("a=%lf b=%lf sum=%lf num=%lf\n",a,b,sum,num);
		}
		ans=(num!=0)?sum/num:0.0;
		printf("%lf\n",ans);
	}
	return 0;
}

