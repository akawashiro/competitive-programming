#include <algorithm>
#include <utility>
#include <vector>

#define INF (1<<29)
using namespace std;

class TheSumOfLuckyNumbers
{
	public:

		int DP[1000000+1];
		
		bool isLucky(int n)
		{
			while(0<n)
				if(n%10!=4 && n%10!=7)
					return false;
				else
					n/=10;
			return true;
		}

		vector <int> sum(int n)
		{
			vector<int> v;
			for(int i=1;i<1000000;i++)
				if(isLucky(i))
					v.push_back(i);
			for(int i=0;i<=1000000;i++)
				DP[i]=INF;
			DP[0]=0;
			for(int i=0;i<=1000000;i++)
				for(int j=0;j<v.size();j++)
					if(0<=i-v[j])
						DP[i]=min(DP[i],DP[i-v[j]]+1);

			int cnt=DP[n];
			vector<int> ans;
			if(cnt==INF)
				return ans;

			while(0<cnt)
			{
				int i;
				for(i=0;;i++)
					if(DP[n-v[i]]==cnt-1)
						break;
				ans.push_back(v[i]);
				n-=v[i];
				cnt--;;
			}

			return ans;
		}
};

