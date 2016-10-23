#include <cmath>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Q
{
	public:
		int y,x,c;
};

class PizzaDelivery
{
	public:

		int cost[55][55];

		int deliverAll(vector<string> terrain)
		{
			int h=terrain.size(),w=terrain[0].size();

			Q q;
			queue<Q> que;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					cost[i][j]=(1<<25);
					if(terrain[i][j]=='X')
					{
						q.y=i,q.x=j,q.c=0;
						que.push(q);
					}
				}

			int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
			while(!que.empty())
			{
				int y=que.front().y;
				int x=que.front().x;
				int c=que.front().c;
				que.pop();

				if(cost[y][x] <= c)
					continue;
				cost[y][x]=c;

				for(int i=0;i<4;i++)
				{
					int yy=y+mv[i][0],xx=x+mv[i][1],cc=c;
					if(yy<0 || h<=yy || xx<0 || w<=xx)
						continue;

					if(terrain[y][x]=='$' || terrain[yy][xx]=='$')
						cc+=2;
					else if(terrain[y][x]=='X' || terrain[yy][xx]=='X')
						cc+=2;
					else if(terrain[y][x] == terrain[yy][xx])
						cc+=1;
					else if((int)abs(terrain[y][x]-terrain[yy][xx])==1)
						cc+=3;
					else
						continue;
						
					q.y=yy,q.x=xx,q.c=cc;
					que.push(q);
				}
			}

			vector<int> dist;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(terrain[i][j]=='$')
						if((1<<25) <= cost[i][j])
							return -1;
						else
							dist.push_back(cost[i][j]);

			int n=dist.size();
			int ans=(1<<25);
			for(int mask=0;mask<(1<<n);mask++)
			{
				int a=0,b=0,amax=0,bmax=0;
				for(int i=0;i<n;i++)
					if(mask & (1<<i))
					{
						a+=dist[i]*2;
						amax=max(amax,dist[i]);
					}
					else
					{
						b+=dist[i]*2;
						bmax=max(bmax,dist[i]);
					}
				
				ans=min(ans,max(a-amax,b-bmax));
			}

			return ans;
		}
};

