#include <vector>
#include <string>
using namespace std;
typedef long long LL;

class CorporationSalary
{
	public:

		vector<LL> cache;
		vector <string> rel;
		int n;

		LL getSalary(int x)
		{
			if(cache[x]!=-1)
				return cache[x];
			LL r=0;
			for(int i=0;i<n;i++)
				if(rel[x][i]=='Y')
					r+=getSalary(i);
			cache[x]=(r==0) ? 1 : r;
			return cache[x];
		}

		LL totalSalary(vector <string> _rel)
		{
			rel=_rel;
			n=rel.size();
			for(int i=0;i<n;i++)
				cache.push_back(-1);

			LL ans=0;
			for(int i=0;i<n;i++)
				ans+=getSalary(i);

			return ans;
		}
};
