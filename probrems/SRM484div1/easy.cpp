#include <cstdio>
using namespace std;
typedef long long LL;

class RabbitNumber
{
	public:

		LL low;
		LL high;

		LL S(LL n)
		{
			LL ans=0;
			while(0<n)
			{
				ans+=(n%10);
				n/=10;
			}
			return ans;
		}

		LL rec(LL n)
		{
			int r=0;
			if(low<=n && n<=high && S(n*n)==S(n)*S(n))
				r++;
			if(n<=high)
			{
				r+=rec(n*10+0);
				r+=rec(n*10+1);
				r+=rec(n*10+2);
				r+=rec(n*10+3);
			}
			return r;
		}

		int theCount(int clow, int chigh)
		{
			low=clow;
			high=chigh;
			int ans=0;
			if(low==0)
				ans++;
			ans+=rec(1);
			ans+=rec(2);
			ans+=rec(3);
			return ans;
		}

};
