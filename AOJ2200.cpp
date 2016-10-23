#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

int n,m;
LL land[200][200];
LL sea[200][200];

#define INF (1LL<<50)

void solve()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				land[i][j]=0;
				sea[i][j]=0;
			}
			else
			{
				land[i][j]=INF;
				sea[i][j]=INF;
			}
		}

	for(int i=0;i<m;i++)
	{
		int x,y;
		LL t;
		char c;
		scanf("%d %d %lld %c",&x,&y,&t,&c);
		x--,y--;

		if(c=='L' && t<land[x][y])
			land[x][y]=land[y][x]=t;
		if(c=='S' && t<sea[x][y])
			sea[x][y]=sea[y][x]=t;
	}

	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				land[i][j]=min(land[i][j],land[i][k]+land[k][j]);
				sea[i][j]=min(sea[i][j],sea[i][k]+sea[k][j]);
			}

	int r,now;
	vector<LL> DP(200,INF);

	scanf("%d%d",&r,&now);
	now--;
	DP[now]=0;

	for(int time=1;time<r;time++)
	{
		int goal;
		vector<LL> next(200,INF);
		scanf("%d",&goal);
		goal--;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==j)
					next[j]=min(next[j],DP[i]+land[now][goal]);
				else
					next[j]=min(next[j],DP[i]+land[now][i]+sea[i][j]+land[j][goal]);
			}
		DP=next;
		now=goal;
	}

	LL ans=INF;
	for(int i=0;i<n;i++)
		ans=min(ans,DP[i]);

	printf("%lld\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)
			break;
		solve();
	}
	return 0;
}

