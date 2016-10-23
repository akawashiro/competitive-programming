#include <set>
#include <map>
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
#include <functional>

#define INF (1<<28)

using namespace std;

int n,m;

void solve()
{
	vector<pair<int,int> > candiate(m);
	for(int i=0;i<m;i++)
	{
		candiate[i].first=0;
		candiate[i].second=i+1;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			char c;
			cin >> c;
			if(c=='1')
				candiate[j].first++;
		}
	for(int i=0;i<m;i++)
		candiate[i].first=(candiate[i].first<<16)-candiate[i].second;

	stable_sort(candiate.begin(),candiate.end(),greater<pair<int,int> >());

	for(int i=0;i<m;i++)
	{
		if(0<i)
			cout << " ";
		cout << candiate[i].second;
	}
	cout << endl;
}

int main()
{
	while(1)
	{
		cin >> n >> m;
		if(n==0 && m==0)
			break;
		solve();
	}
	return 0;
}

