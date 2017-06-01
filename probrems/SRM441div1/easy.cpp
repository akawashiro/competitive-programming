#include <vector>
#include <algorithm>
using namespace std;

class PerfectPermutation
{
	public:
		int reorder(vector <int> P)
		{
			int ans=0;
			while(count(P.begin(),P.end(),-1)!=P.size())
			{
				int p;
				for(p=0;p<P.size();p++)
					if(P[p]!=-1)
						break;
				while(P[p]!=-1)
				{
					int a=p;
					p=P[a];
					P[a]=-1;
				}
				ans++;
			}
			return (ans==1) ? 0 : ans;
		}
};
