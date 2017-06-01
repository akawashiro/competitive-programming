#include <sstream>
#include <string>
#include <vector>

using namespace std;

class TaxiManager
{
	public:

		int dist[50][50];
		int DP[12][(1<<12)];
		int cost[(1<<12)];

		int schedule(vector<string> roads, vector<string> _customers)
		{
			int n=roads.size();
			int cn=_customers.size();
			vector<int> from(cn);
			vector<int> to(cn);

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					if(i==j)
						dist[i][j]=0;
					else if(roads[i][j]!='0')
						dist[i][j]=roads[i][j]-'0';
					else
						dist[i][j]=(1<<28);
			}
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
						
			for(int i=0;i<cn;i++)
			{
				stringstream ss(_customers[i]);
				ss >> from[i] >> to[i];
			}
			
			for(int i=0;i<(1<<cn);i++)
				for(int j=0;j<cn;j++)
					DP[j][i]=(1<<28);
			for(int state=0;state<(1<<cn);state++)
				for(int now=0;now<cn;now++)
					if(state & (1<<now))
					{
						DP[now][state]=dist[from[now]][to[now]];
						int add;
						if(state==(1<<now))
							add=dist[to[now]][0];
						else
						{
							add=(1<<28);
							for(int next=0;next<cn;next++)
								if((state & (1<<next)) && next!=now)
									add=min(add,dist[to[now]][from[next]]+DP[next][(state - (1<<now))]);
						}
						DP[now][state]+=add;

					}

			for(int mask=0;mask<(1<<cn);mask++)
			{
				cost[mask]=(1<<28);
				for(int s=0;s<cn;s++)
					if(mask & (1<<s))
						cost[mask]=min(cost[mask],dist[0][from[s]]+DP[s][mask]);
			}
			cost[0]=0;

			int ans=(1<<28);
			
			for(int mask=0;mask<(1<<cn);mask++)
				ans=min(ans,max(cost[mask],cost[(1<<cn)-1-mask]));

			return ans;
		}
};

