#include <algorithm>

using namespace std;

int cache[100000+1];

class DivisorInc
{
	public:

		int M;

		int rec(int num)
		{
			if(M<num)
				return (1<<28);
			if(cache[num]!=-1)
				return cache[num];
				
			cache[num]=(1<<28);
			for(int i=2;i*i<=num;i++)
				if(num%i==0)
				{
					cache[num]=min(cache[num],1+rec(num+i));
					cache[num]=min(cache[num],1+rec(num+num/i));
				}
			return cache[num];
		}

		int countOperations(int N, int _M)
		{
			M=_M;
			fill(&cache[0],&cache[100000],-1);
			cache[M]=0;

			int ans=rec(N);
			ans=((1<<28)<=ans) ? -1 : ans;

			return ans;
		}
};

