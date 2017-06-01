#include <vector>
#include <cstdio>

typedef long long LL;
using namespace std;

class ChristmasTree
{
	public:

		LL cache[10+1][50+1][50+1][50+1];
		int N;

		LL C(LL n,LL r)
		{
			LL l=1;
			for(LL i=n-r+1;i<=n;i++)
				l*=i;
			for(LL i=1;i<=r;i++)
				l/=i;
			return l;
		}

		LL rec(int L,int R,int G,int B)
		{
			if(R<0 || G<0 || B<0)
				return 0;
			if(L==N+1)
				return 1;

			LL *p=&cache[L][R][G][B];

			if(*p!=-1)
				return *p;

			LL r=0;
			int l=L;

			r+=rec(L+1,R-l,G,B)+rec(L+1,R,G-l,B)+rec(L+1,R,G,B-l);

			if(L%2==0)
			{
				l=L/2;
				r+=(rec(L+1,R-l,G-l,B)+rec(L+1,R,G-l,B-l)+rec(L+1,R-l,G,B-l))*C(L,l);
			}

			if(L%3==0)
			{
				l=L/3;
				r+=rec(L+1,R-l,G-l,B-l)*C(L,l)*C(L-l,l);
			}

			return *p=r;
		}

		LL decorationWays(int NN, int red, int green, int blue)
		{
			N=NN;
			memset(cache,-1,sizeof(cache));

			return rec(1,red,green,blue);
		}
};

