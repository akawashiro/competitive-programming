#include <vector>
#include <map>
using namespace std;
typedef long long LL;

class RandomSort
{
	public:

		int n;

		map<vector<int>,double> cache;

		double DFS(vector<int> perm)
		{
			if(cache.find(perm)!=cache.end())
				return cache[perm];

			int i,j;
			for(i=1;i<n;i++)
				if(perm[i-1]>perm[i])
					break;
			if(i==n)
			{
				return 0.0;
			}

			double result=0.0,d=0.0;
			for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
					if(perm[i]>perm[j])
					{
						swap(perm[i],perm[j]);
						result+=DFS(perm);
						d++;
						swap(perm[i],perm[j]);
					}

			return cache[perm]=result/d+1.0;
		}

		double getExpected(vector <int> perm)
		{
			n=perm.size();
			return DFS(perm);;
		}
};
