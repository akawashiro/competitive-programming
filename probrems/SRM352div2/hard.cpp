#include <vector>

#define EPS 1e-16
using namespace std;

class RaceManagement
{
	public:

		int popCount(int mask)
		{
			int r=0;
			for(int i=0;i<25;i++)
				if(mask & (1<<i))
					r++;
			return r;
		}

		double getPayoutFactor(vector<int> _p,vector<int> _a,int _m)
		{
			int n=_p.size();
			double minimum=_m;
			vector<double> probability,amount;
			for(int i=0;i<n;i++)
			{
				probability.push_back((double)_p[i]/100.0);
				amount.push_back((double)_a[i]);
			}

			double x=0.0,y=0.0;
			for(int mask=0;mask<(1<<n);mask++)
			{
				double p=1.0;
				for(int i=0;i<n;i++)
					if((1<<i) & mask)
						p*=probability[i];
					else
						p*=(1-probability[i]);

				if(popCount(mask)==1)
				{
					for(int i=0;i<n;i++)
						if((1<<i) & mask)
							y-=(p*amount[i]);
						else
							x+=(p*amount[i]);
				}
				else
				{
					for(int i=0;i<n;i++)
						x+=(p*amount[i]);
				}
			}
			
			//printf("x=%lf y=%lf\n",x,y);

			if(0.0-EPS<y && y<0.0+EPS)
				if(minimum-EPS<x)
					return -2;
				else
					return -1;
			double ans=(minimum-x)/y;
			if(ans<0.0)
				return -1;
			return ans;
		}
};

