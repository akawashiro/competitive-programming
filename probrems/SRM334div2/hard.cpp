#include <algorithm>
#include <cstring>
#define LIMIT 5000000

typedef long long LL;
using namespace std;

class ExtendedHappyNumbers
{
	public:

		int K;
		int happiness[LIMIT];

		int rec(int now)
		{
			if(0<happiness[now])
				return happiness[now];
			happiness[now]--;
			if(happiness[now]==-3)
				return now;

			int n=0;
			int t=now;
			while(t!=0)
			{
				int s=1;
				for(int j=0;j<K;j++)
					s*=(t%10);
				n+=s;
				t/=10;
			}
			happiness[now]=min(now,rec(n));
			return happiness[now];
		}

		LL calcTheSum(int A, int B, int _K)
		{
			K=_K;
			memset(happiness,0,sizeof(happiness));
			LL ans=0;
			for(LL i=A;i<=B;i++)
				ans+=(LL)rec(i);
			return ans;
		}
};



