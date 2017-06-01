#include <vector>
using namespace std;

class Underprimes
{
	public:
		int howMany(int A, int B)
		{
			int isPrime[100000+1];
			for(int i=0;i<=100000;i++)
				isPrime[i]=-1;
			isPrime[0]=isPrime[1]=0;
			while(1)
			{
				bool isLeft=false;
				int p;
				for(int i=0;i<=100000;i++)
					if(isPrime[i]==-1)
					{
						isLeft=true;
						p=i;
						break;
					}
				if(!isLeft)
					break;
				isPrime[p]=1;
				for(int i=p+p;i<=100000;i+=p)
					isPrime[i]=0;
			}
			vector<int> primes;
			for(int i=0;i<=100000;i++)
				if(isPrime[i]==1)
					primes.push_back(i);

			int ans=0;
			for(int num=A;num<=B;num++)
			{
				int nUnder=0;
				int n=num;
				while(n!=1)
				{
					for(int i=0;i<primes.size();i++)
						if(n%primes[i]==0)
						{
							n/=primes[i];
							nUnder++;
							break;
						}
				}
				if(isPrime[nUnder]==1)
					ans++;
			}
			return ans;
		}
};

