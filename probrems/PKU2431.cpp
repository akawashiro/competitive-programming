#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
typedef long long LL;

void solve()
{
	int n,ans=0,L,P;
	cin >> n;
	vector<pair<int,int> > stops;
	priority_queue<int> que;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		stops.push_back(make_pair(a,b));
	}
	stops.push_back(make_pair(0,0));
	n++;
	cin >> L >> P;
	for(int i=0;i<n;i++)
		stops[i].first=L-stops[i].first;
	sort(stops.begin(),stops.end());
	int d=stops[0].first;
	//printf("stops[0].first=%d\n",stops[0].first);
	for(int i=1;i<n;i++)
	{
		int e=d;
		d=stops[i].first;
		stops[i].first-=e;
		//printf("stops[%d].first=%d\n",i,stops[i].first);
	}

	for(int i=0;i<n;i++)
	{
		P-=stops[i].first;
		while(P<0)
		{
			if(que.empty())
			{
				cout << "-1" << endl;
				return;
			}
			ans++;
			P+=que.top();
			que.pop();
		}
		que.push(stops[i].second);
	}

	cout << ans << endl;
	return;
}

int main()
{
	solve();
	return 0;
}

