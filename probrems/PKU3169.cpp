#include <vector>
#include <utility>
#include <stdio.h>
#include <limits.h>

using namespace std;

int dist[1010];
vector<pair<int,int> > G[1010];

int main()
{
	int N,ML,MD;
	scanf("%d%d%d",&N,&ML,&MD);

	for(int i=0;i<ML;i++)
	{
		int A,B,D;
		scanf("%d%d%d",&A,&B,&D);
		G[A].push_back(make_pair(D,B));
	}
	for(int i=0;i<MD;i++)
	{
		int A,B,D;
		scanf("%d%d%d",&A,&B,&D);
		G[B].push_back(make_pair(-D,A));
	}
	for(int i=2;i<=N;i++)
		G[i].push_back(make_pair(0,i-1));
	for(int i=0;i<1010;i++)
		dist[i]=INT_MAX/2;
	dist[1]=0;
	for(int k=0;k<=N;k++)
		for(int i=0;i<=N;i++)
			for(int j=0;j<G[i].size();j++)
				dist[G[i][j].second]=min(dist[G[i][j].second],dist[i]+G[i][j].first);
	int r=dist[N];
	if(dist[1]<0)
		r=-1;
	else if(r==INT_MAX/2)
		r=-2;
	printf("%d\n",r);
}


