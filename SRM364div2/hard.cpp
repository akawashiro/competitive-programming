#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class PowerPlants
{
	public:
		int n,aim;
		int cache[(1<<16)];
		vector<string> cost;

		int popCount(int num)
		{
			int r=0;
			for(int i=0;i<n;i++)
				if(num & (1<<i))
					r++;
			return r;
		}

		int rec(int state)
		{
			int &r=cache[state];
			if(r!=-1)
				return r;
			if(aim <= popCount(state))
				return r=0;

			r=(1<<28);
			for(int i=0;i<n;i++)
			{
				if(state & (1<<i))
					continue;

				for(int j=0;j<n;j++)
					if(state & (1<<j))
						r=min(r,cost[j][i]+rec( (state | (1<<i)) ));
			}

			return r;
		}

		int minCost(vector<string> _cost,string active,int _aim)
		{
			cost=_cost;
			n=cost.size();
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					char c=cost[i][j];
					if('0'<=c && c<='9')
						c-='0';
					else if('A'<=c && c<='Z')
					{
						c-='A';
						c+=10;
					}
					cost[i][j]=c;
				}
			aim=_aim;

			fill(&cache[0],&cache[(1<<n)],-1);

			int state=0;
			for(int i=0;i<n;i++)
				if(active[i]=='Y')
					state=( state | (1<<i) );

			return rec(state);
		}
};

