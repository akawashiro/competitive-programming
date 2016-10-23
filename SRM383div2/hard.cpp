#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class EDGE
{
	public:
		int to,cost;
		bool operator <(const EDGE &e)
			const
			{
				return !(cost<e.cost);
			}
};

class HillWalker
{
	public:
		int h,w,limit,thres;
		vector<string> map;

		int dist(int a,int b)
		{
			int y1=a/w,x1=a%w,y2=b/w,x2=b%w;
			if(thres < abs(map[y1][x1]-map[y2][x2]))
				return (1<<29);
			if(map[y1][x1] < map[y2][x2])
			{
				int i=map[y1][x1]-map[y2][x2];
				i*=i;
				return i;
			}
			else
				return 1;
		}

		int highestPoint(vector<string> _map,int _thres,int _limit)
		{
			map=_map;
			thres=_thres;
			limit=_limit;
			h=map.size();
			w=map[0].size();
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					char c=map[i][j];
					if('A'<=c && c<='Z')
						c-='A';
					else if('a'<=c && c<='z')
					{
						c-='a';
						c+=26;
					}
					map[i][j]=c;
				}
			
			/*printf("map\n");
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
					printf("%4d",map[i][j]);
				printf("\n");
			}*/

			vector<vector<int> > toCost(h,vector<int>(w,(1<<29)));
			vector<vector<int> > fromCost(h,vector<int>(w,(1<<29)));

			int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
			EDGE e;
			priority_queue<EDGE> que;

			e.cost=0,e.to=0;
			que.push(e);
			while(!que.empty())
			{
				e=que.top();
				que.pop();
				int y=e.to/w,x=e.to%w,c=e.cost;
				if(c < toCost[y][x])
				{
					toCost[y][x]=c;
					for(int i=0;i<4;i++)
					{
						int yy=y+mv[i][0],xx=x+mv[i][1];
						if(0<=yy && yy<h && 0<=xx && xx<w)
						{
							e.to=yy*w+xx;
							e.cost=toCost[y][x]+dist(y*w+x,yy*w+xx);
							que.push(e);
						}
					}
				}
			}
			
			/*printf("toCost\n");
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
					printf("%4d",toCost[i][j]);
				printf("\n");
			}*/

			e.cost=0,e.to=0;
			que.push(e);
			while(!que.empty())
			{
				e=que.top();
				que.pop();
				int y=e.to/w,x=e.to%w,c=e.cost;
				if(c < fromCost[y][x])
				{
					fromCost[y][x]=c;
					for(int i=0;i<4;i++)
					{
						int yy=y+mv[i][0],xx=x+mv[i][1];
						if(0<=yy && yy<h && 0<=xx && xx<w)
						{
							e.to=yy*w+xx;
							e.cost=fromCost[y][x]+dist(yy*w+xx,y*w+x);
							que.push(e);
						}
					}
				}
			}
			
			/*printf("fromCost\n");
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
					printf("%4d",fromCost[i][j]);
				printf("\n");
			}*/

			int ans=0;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(toCost[i][j]+fromCost[i][j] <= limit)
						ans=max(ans,(int)map[i][j]);

			return ans;
		}
};

