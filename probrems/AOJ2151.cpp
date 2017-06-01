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

int N,M,L;

class Q
{
	public:
		int cost,pos,money;
		bool operator <(const Q q)
		const{
			return (Q::cost > q.cost); //priority_queueは通常降順
		}
};

void solve()
{
	int danger[100][100];
	int money[100][100];
	memset(danger,-1,sizeof(danger));
	memset(money,-1,sizeof(money));

	for(int i=0;i<M;i++)
	{
		int a,b,d,e;
		cin >> a >> b >> d >> e;
		a--,b--;
		danger[a][b]=danger[b][a]=e;
		money[a][b]=money[b][a]=d;
	}

	int dist[100][100+1];
	bool isVisited[100][100+1];
	for(int i=0;i<100;i++)
		for(int j=0;j<100+1;j++)
		{
			dist[i][j]=(1<<28);
			isVisited[i][j]=false;
		}

	Q q;

	priority_queue<Q> que;

	q.cost=0,q.pos=0,q.money=L;
	que.push(q);

	while(!que.empty())
	{
		int c=que.top().cost,p=que.top().pos,m=que.top().money;
		que.pop();
		if(!isVisited[p][m] && c<dist[p][m])
		{
			dist[p][m]=c;
			isVisited[p][m]=true;
			for(int i=0;i<N;i++)
			{

				if(danger[p][i]==-1)
					continue;
				int di=danger[p][i];
				int mi=money[p][i];
				if(0<=m-mi)
				{
					q.cost=c,q.pos=i,q.money=m-mi;
					que.push(q);
				}
				q.cost=c+di,q.pos=i,q.money=m;
				que.push(q);
			}
		}
	}

	int ans=(1<<28);
	for(int i=0;i<=L;i++)
	{
		int d=dist[N-1][i];
		if(d==-1)
			continue;
		ans=min(ans,d);
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> N >> M >> L;
		if(N==0 && M==0 && L==0)
			break;
		solve();
	}
	return 0;
}

