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

int m;

void solve()
{
	vector<pair<int,int> > target(m);
	for(int i=0;i<m;i++)
		cin >> target[i].first >> target[i].second;
	sort(target.begin(),target.end());

	int n;
	cin >> n;
	vector<pair<int,int> > star(n);
	for(int i=0;i<n;i++)
		cin >> star[i].first >> star[i].second;
	sort(star.begin(),star.end());

	for(int i=0;i<n;i++)
	{
		int xdiff=star[i].first-target[0].first;
		int ydiff=star[i].second-target[0].second;

		int j;
		for(j=0;j<m;j++)
		{
			pair<int,int> p;
			p.first=target[j].first+xdiff;
			p.second=target[j].second+ydiff;

			if(!binary_search(star.begin(),star.end(),p))
				break;
		}
		if(j==m)
		{
			cout << xdiff << " " << ydiff << endl;
			break;
		}
	}
}

int main()
{
	while(1)
	{
		cin >> m;
		if(m==0)
			break;
		solve();
	}
	return 0;
}

