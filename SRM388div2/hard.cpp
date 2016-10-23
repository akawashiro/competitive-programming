#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class SmoothNumbersHard
{
	public:
	
		int countSmoothNumbers(int n, int k)
		{
			vector<int> p(n+1,0);
			for(int i=2;i<=n;i++)
				if(!p[i])
					for(int j=i;j<=n;j+=i)
						p[j]=i;
			
			int ans=0;
			for(int i=1;i<=n;i++)
				if(p[i]<=k)
					ans++;
			return ans;
		}
};

