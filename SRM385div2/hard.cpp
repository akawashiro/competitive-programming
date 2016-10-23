#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

class SummingArithmeticProgressions
{
	public:

		int gcd(int a,int b)
		{
			if(b==0)	return a;
			else	return gcd(b,a%b);
		}

		int lcm(int a,int b)
		{
			return a*b/gcd(a,b);
		}

		int popCount(LL b)
		{
			int r=0;
			for(LL i=0;i<60;i++)
				if(b & (LL(1)<<i))
					r++;
			return r;
		}

		int calc(int n,int k)
		{
			int a0=k*(k+1)/2,r=0,a=k,b=k*(k-1)/2,t;
			LL bit=0;
			n-=a0;
			if(n<0)	return 0;
			t=(n-lcm(a,b))/gcd(a,b);	
			if(0<t)	r+=t;
			for(int i=0;i*a<=min(lcm(a,b),n);i++)
				for(int j=0;i*a+j*b<=min(lcm(a,b),n);j++)
				{
					LL x=i*a+j*b;
					//printf("x=%lld\n",x);
					bit |= ((LL)1<<x);
				}
			r+=popCount(bit);

			printf("a=%d b=%d n=%d a0=%d gcd(a,b)=%d lcm(a,b)=%d popCount(bit)=%d r=%d\n",a,b,n,a0,gcd(a,b),lcm(a,b),popCount(bit),r);

			return r;
		}

		int howMany(int left, int right, int k)
		{
			return calc(right,k)-calc(left-1,k);
		}
};

