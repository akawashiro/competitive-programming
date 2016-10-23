#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>
#include <functional>

using namespace std;
vector<pair<int,int> > G[5010];
int dist[5010][2];

int main()
{
	int N,R;
	scanf("%d%d",&N,&R);
	for(int i=0;i<R;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(make_pair(c,b));
		G[b].push_back(make_pair(c,a));
	}
	for(int i=1;i<=N;i++)
		for(int j=0;j<2;j++)
			dist[i][j]=INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
	que.push(make_pair(0,1));
	dist[1][0]=0;
	while(!que.empty())
	{
		int c,d;
		c=que.top().first;
		d=que.top().second;
		que.pop();
		//printf("c=%d d=%d\n",c,d);
		if(dist[d][1]<c)
			continue;
		//dist[d][1]=c;
		//if(dist[d][1]<dist[d][0])
		//	swap(dist[d][1],dist[d][0]);
		for(int i=0;i<G[d].size();i++)
		{
			int cc=c+G[d][i].first;
			int dd=G[d][i].second;
			if(cc<dist[dd][0])
			{
				swap(dist[dd][0],cc);
				que.push(make_pair(dist[dd][0],dd));
			}
			if(cc<dist[dd][1] && cc>dist[dd][0])
			{
				dist[dd][1]=cc;
				que.push(make_pair(cc,dd));
			}
		}
	}
	printf("%d\n",dist[N][1]);
	return 0;
}

