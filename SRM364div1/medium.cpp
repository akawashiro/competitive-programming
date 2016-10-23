#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<28;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

class Q
{
	public:
		int cost,state;
		bool operator<(const Q &q)const{	return q.cost<cost;	}
};

class PowerPlants
{
	public:

		int dist[(1<<17)];

		int minCost(vector <string> connectionCost, string plantList, int numPlants)
		{
			int n=plantList.size(),ans=(1<<28);
			fill(dist,&dist[(1<<17)-1],(1<<28));
			Q q;
			priority_queue<Q> que;

			q.cost=0,q.state=0;
			for(int i=0;i<n;i++)
				if(plantList[i]=='Y')
					q.state+=(1<<i);

			que.push(q);

			while(!que.empty())
			{
				int c=que.top().cost,s=que.top().state;
				que.pop();
				
				/*for(int i=0;i<n;i++)
					if(s&(1<<i))
						printf("Y");
					else
						printf("N");
				printf("=%d\n",c);*/
				
				if(c<dist[s])
				{
					dist[s]=c;	
					if(popCount(s)<numPlants)
					{
						for(int i=0;i<n;i++)
							if(s&(1<<i))
								for(int j=0;j<n;j++)
									if(!(s&(1<<j)))
									{
										q.state=s+(1<<j);
										char ch=connectionCost[i][j];
										int add=('0'<=ch && ch<='9')?(ch-'0'):(ch-'A'+10);
										//printf("c=%d add=%d\n",c,add);
										q.cost=c+add;
										
										//printf("%d->%d i=%d j=%d\n",c,q.cost,i,j);
										
										que.push(q);
									}
					}
					else
					{
						//printf("ans=min(ans,c);\n");
						ans=min(ans,c);
					}
				}
			}

			return ans;
		}
};

