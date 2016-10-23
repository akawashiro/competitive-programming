#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>

#define INF (1<<28)

using namespace std;
typedef pair<int,int> EDGE;

int N,M,L,K,A,H;

void solve()
{
	vector<int> freeze;
	vector<vector<EDGE> > input(N);
	for(int i=0;i<L;i++)
	{
		int a;
		cin >> a;
		freeze.push_back(a);
	}
	for(int i=0;i<K;i++)
	{
		int X,Y,T;
		EDGE e;
		cin >> X >> Y >> T;
		e.second=Y,e.first=T;	input[X].push_back(e);
		e.second=X,e.first=T;	input[Y].push_back(e);
	}

	vector<vector<EDGE> > G(20000);
	for(int point=0;point<N;point++)
		for(int left=0;left<=M;left++)
		{
			if(left<M && find(freeze.begin(),freeze.end(),point)!=freeze.end())
				G[point+left*N].push_back(make_pair(1,point+(left+1)*N));

			for(int t=0;t<(int)input[point].size();t++)
			{
				EDGE e=input[point][t];
				if(0 <= left-e.first)
					G[point+left*N].push_back(make_pair(e.first,e.second+(left-e.first)*N));
			}
		}

	vector<int> dist(20000,INF);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > que;
	
	que.push(make_pair(0,A+M*N));
	
	while(!que.empty())
	{
		pair<int,int> q=que.top();
		que.pop();

		if(q.first < dist[q.second])
		{
			dist[q.second]=q.first;
			for(int i=0;i<(int)G[q.second].size();i++)
				que.push(make_pair(G[q.second][i].first+dist[q.second],
							G[q.second][i].second));
		}
	}

	int ans=INF;
	for(int i=0;i<=M;i++)
		ans=min(ans,dist[H+i*N]);

	if(ans==INF)
		cout << "Help!" << endl;
	else
		cout << ans << endl;
	
}

int main()
{
	while(1)
	{
		cin >> N >> M >> L >> K >> A >> H;
		if(N==0 && M==0)
			break;
		solve();
	}
	return 0;
}

