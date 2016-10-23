#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <climits>
#include <cstdio>

#define T_MAX 10000+10
#define INF (1<<28)
using namespace std;

struct EDGE
{
	int to,cost;
};

class OnTime
{
	public:

		int minCost(int N, int T, vector<string> buses)
		{
			vector<EDGE> G[50][T_MAX];
			EDGE e;

			for(int i=0;i<50;i++)
				for(int j=0;j<T_MAX-1;j++)
				{
					e.to=(i<<18)+(j+1);
					e.cost=0;
					G[i][j].push_back(e);
					
					if((j+1)&0xffff < (j+1))
						printf("j==%d\n",j);
				}

			for(int i=0;i<(int)buses.size();i++)
			{
				stringstream ss(buses[i]);
				int a,b,dep,time,cost;
				ss >> a >> b >> dep >> time >> cost;

				e.to=(b<<18)+dep+time+1,e.cost=cost;

				G[a][dep].push_back(e);
			}

			int dist[50][T_MAX];
			for(int i=0;i<50;i++)
				for(int j=0;j<T_MAX;j++)
					dist[i][j]=INF;
					
			queue<EDGE> que;
			e.to=(0<<18)+0,e.cost=0;
			que.push(e);

			while(!que.empty())
			{
				int to=que.front().to,cost=que.front().cost;
				int pos=(to>>18),time=(to&0xffff);
				que.pop();

				if(dist[pos][time]<=cost)
					continue;

				dist[pos][time]=cost;
				for(int i=0;i<(int)G[pos][time].size();i++)
				{
					e.cost=cost+G[pos][time][i].cost;
					e.to=G[pos][time][i].to;
					
					if(e.cost==0 && (e.to>>18)==N-1)
						printf("e.to=%x pos=%d time=%d cost=%d\n",e.to,pos,time,cost);

					
					que.push(e);
				}
			}

			int ans=INF;
			for(int i=0;i<=T+1;i++)
			{
				ans=min(ans,dist[N-1][i]);
				//printf("dist[%d][%d]=%d\n",N-1,i,dist[N-1][i]);
			}
			if(ans==INF)
				ans=-1;

			return ans;
		}
};

