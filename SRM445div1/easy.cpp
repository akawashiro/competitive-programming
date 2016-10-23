#include <vector>
#include <algorithm>
using namespace std;

class TheNewHouseDivOne
{
	public:
		double distance(vector <int> x, vector <int> y, int k)
		{
			int n=x.size();
			double ans=100000000;
			for(int i=0;i<n;i++)
				x[i]*=2,y[i]*=2;
			for(int ansX=-100;ansX<=100;ansX++)
				for(int ansY=-100;ansY<=100;ansY++)
				{
					vector<double> dist;
					for(int i=0;i<n;i++)
						dist.push_back(abs(ansX-x[i])+abs(ansY-y[i]));
					sort(dist.begin(),dist.end());
					ans=min(ans,dist[k-1]/2.0);
				}
			return ans;
		}
};

