#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

#define INF (1<<28)

int n,k;
vector<vector<int> > G;

void show()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int a=G[i][j];
			if(a==INF)
				a=-1;
			printf("%6d",a);
		}
		printf("\n");
	}
	printf("\n");
}

int calc(int start,int goal)
{
	vector<int> dist(n,INF);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;

	que.push(make_pair(0,start));

	while(!que.empty())
	{
		int cost=que.top().first,to=que.top().second;
		que.pop();

		if(cost < dist[to])
		{
			dist[to]=cost;
			for(int i=0;i<n;i++)
				if(G[to][i]<INF)
					que.push(make_pair(dist[to]+G[to][i],i));
		}
	}

	return dist[goal];
}

void solve()
{
	G.clear();
	G=vector<vector<int> >(n,vector<int>(n,INF));

	for(int i=0;i<k;i++)
	{
		int t;
		cin >> t;

		//show();

		if(t==0)
		{
			int a,b,r;
			cin >> a >> b;
			r=calc(a-1,b-1);
			if(r==INF)
				r=-1;
			cout << r << endl;
		}
		if(t==1)
		{
			int c,d,e;
			cin >> c >> d >> e;
			c--;
			d--;
			G[c][d]=min(G[c][d],e);
			G[d][c]=min(G[d][c],e);
		}
	}
}

int main()
{
	while(1)
	{
		cin >> n >> k;
		if(n==0 && k==0)
			break;
		solve();
	}
	return 0;
}

