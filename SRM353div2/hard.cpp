#include <cstring>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define EPS 1e-9
using namespace std;

class PlatformJumper
{
	public:
		int n,v,g;
		vector<int> x;
		vector<int> y;
		vector<int> coin;

		int cache[50];

		bool isCan(int from,int to)
		{
			double yDif=y[from]-y[to];
			double xDif=abs(x[from]-x[to]);
			if(yDif<0+EPS)
				return false;
			double t=sqrt(2.0*yDif/g);
			return (xDif<v*t+EPS);
		}

		int rec(int s)
		{
			int &r=cache[s];
			if(r!=-1)
				;
			else
			{
				r=0;
				for(int i=0;i<n;i++)
					if(isCan(s,i))
						r=max(r,rec(i));
				r+=coin[s];
			}

			return r;
		}

		int maxCoins(vector<string> platforms,int _v, int _g)
		{
			v=_v;
			g=_g;
			n=platforms.size();
			for(int i=0;i<n;i++)
			{
				stringstream ss(platforms[i]);
				int xx,yy,cc;
				ss >> xx >> yy >> cc;
				x.push_back(xx);
				y.push_back(yy);
				coin.push_back(cc);
			}

			memset(cache,-1,sizeof(cache));
			int ans=0;
			for(int i=0;i<n;i++)
				ans=max(ans,rec(i));
			return ans;
		}
};

