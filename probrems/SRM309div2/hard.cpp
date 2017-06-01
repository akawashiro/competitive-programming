#include <algorithm>
#include <climits>
#include <sstream>
#include <string>
#include <vector>

typedef long long LL;
using namespace std;

LL ABS(LL n)
{
	return (0<=n) ? n : -n;
}

class SynchronizingGuideposts
{
	public:
		LL minCost(vector<string> _guideposts,int C)
		{
			int n=_guideposts.size();
			vector<pair<LL,LL> > guide(n);
			vector<LL> candiate;
			candiate.push_back(0);

			for(int i=0;i<n;i++)
			{
				stringstream ss(_guideposts[i]);
				LL a,b,c;
				ss >> a >> b >> c;
				guide[i].first=a+b;
				guide[i].second=c;
				if(0<=a+b-c)	candiate.push_back(a+b-c);
				if(0<=a+b)		candiate.push_back(a+b);
				if(0<=a+b+c)	candiate.push_back(a+b+c);
			}

			LL ans=LLONG_MAX;
			for(int ci=0;ci<candiate.size();ci++)
			{
				LL t=0;
				LL p=candiate[ci];

				for(int i=0;i<n;i++)
				{
					LL d=ABS(p-guide[i].first);
					t+=d;
					if(guide[i].second<d)
						t+=(d-guide[i].second)*(LL)C;
				}

				ans=min(ans,t);
			}

			return ans;
		}
};

