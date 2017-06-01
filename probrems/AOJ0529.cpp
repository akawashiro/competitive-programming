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

LL N,M;

void solve()
{
	vector<LL> v(N+1);
	for(int i=0;i<N;i++)
		cin >> v[i];
	v[N]=0;

	vector<LL> point((N+1)*(N+1));
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			point[i*(N+1)+j]=(v[i]+v[j]);
	sort(point.begin(),point.end());

	int ans=0;
	for(int i=0;i<point.size();i++)
	{
		vector<LL>::iterator it;
		it=lower_bound(point.begin(),point.end(),M-point[i]+1);
		if(it!=point.begin())
		{
			it--;
			ans=max((LL)ans,(*it)+point[i]);
		}
	}

	cout << ans << endl;
}

int main()
{
	while(1)
	{
		cin >> N >> M;
		if(N==0 && M==0)
			break;

		solve();
	}
	return 0;
}

