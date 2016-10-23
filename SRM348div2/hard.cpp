#include <algorithm>
#include <vector>

typedef long long LL;
using namespace std;

class IncreasingSubsequences
{
	public:
		vector<int> a;
		LL cache[50+1];
		int n;

		LL rec(int last)
		{
			LL &r=cache[last];
			if(r!=-1)
				return r;

			r=0;
			int m=1000000000+10;
			for(int i=last+1;i<n;i++)
				if(a[last]<a[i] && a[i]<m)
				{	
					m=a[i];
					r+=rec(i);
				}

			if(r==0)
				r=1;

			return r;
		}

		LL count(vector<int> _a)
		{
			a=_a;
			reverse(a.begin(),a.end());
			a.push_back(0);
			reverse(a.begin(),a.end());
			fill(&cache[0],&cache[51],-1);
			n=a.size();

			return rec(0);
		}
};

