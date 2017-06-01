#include <cmath>
#include <climits>
#include <vector>
using namespace std;
typedef long long LL;

class TheTower
{
	public:
		vector <int> count(vector <int> x, vector <int> y)
		{
			int n=x.size();
			vector<int> ans(n,INT_MAX);

			for(int xi=0;xi<n;xi++)
				for(int yi=0;yi<n;yi++)
				{
					vector<int> v;
					int x0=x[xi],y0=y[yi];
					for(int i=0;i<n;i++)
						v.push_back(abs(x0-x[i])+abs(y0-y[i]));
					sort(v.begin(),v.end());
					int m=0;
					for(int i=0;i<n;i++)
					{
						m+=v[i];
						ans[i]=min(m,ans[i]);
					}
				}
			return ans;
		}
};

