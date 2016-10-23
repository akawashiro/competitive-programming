#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

class EDGE
{
	public:
		int to,cost;

		bool operator<(const EDGE &e)
		const{
			return (cost>e.cost);
		}
};

class BRANCH
{
	public:
		int left,right,length;
};

int main()
{
	int N,M,K;
	cin >> N >> M >> K;

	vector<vector<EDGE> > G(N);
	vector<int> dist(N,(1<<28));
	priority_queue<EDGE> que;
	vector<BRANCH> branch;

	for(int i=0;i<M;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--,b--;

		EDGE e;
		e.to=b,e.cost=c;
		G[a].push_back(e);
		e.to=a,e.cost=c;
		G[b].push_back(e);

		BRANCH br;
		br.left=a,br.right=b,br.length=c;
		branch.push_back(br);
	}

	for(int i=0;i<K;i++)
	{
		int a;
		cin >> a;
		a--;

		EDGE e;
		e.to=a,e.cost=0;
		que.push(e);
	}

	while(!que.empty())
	{
		int t=que.top().to,c=que.top().cost;
		que.pop();
		
		if(dist[t]<=c)
			continue;

		dist[t]=c;

		for(int i=0;i<(int)G[t].size();i++)
		{
			EDGE e;
			e.to=G[t][i].to;
			e.cost=G[t][i].cost+c;
			que.push(e);
		}
	}

	int ans=0;
	for(int i=0;i<M;i++)
	{
		int a=dist[branch[i].left]+branch[i].length+dist[branch[i].right];
		a+=(a%2==1) ? 1 : 0;
		a/=2;
		ans=max(ans,a);
	}

	cout << ans << endl;
}

