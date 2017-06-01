#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class EDGE{
	public:
		int left,right,cost;
};

int main()
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);

	short G[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			G[i][j]=(1<<13);
			if(i==j)
				G[i][j]=0;
		}

	vector<EDGE> link(M);
	for(int i=0;i<M;i++)
	{
		int a,b,cost;
		scanf("%d %d %d",&a,&b,&cost);
		a--,b--;
		G[a][b]=cost;
		G[b][a]=cost;

		EDGE e;
		e.left=a,e.right=b,e.cost=cost;
		link[i]=e;
	}

	int cost[N];
	for(int i=0;i<N;i++)
		cost[i]=(1<<28);
	for(int i=0;i<K;i++)
	{
		int a;
		scanf("%d",&a);
		a--;
		cost[a]=0;
	}

	/*for(int i=0;i<N;i++)
		printf("%d\n",cost[i]);*/

	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(G[i][j]!=(1<<13))
					cost[i]=min(cost[i],G[i][j]+cost[j]);

	/*for(int i=0;i<N;i++)
		printf("%d\n",cost[i]);*/

	int r=0;
	for(int i=0;i<M;i++)
	{
		int a=cost[link[i].left]+cost[link[i].right]+G[link[i].left][link[i].right];
		if(a%2==1)
			r=max((a+1)/2,r);
		else
			r=max(a/2,r);
	}

	printf("%d\n",r);
}

