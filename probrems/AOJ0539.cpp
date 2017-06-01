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

int d,n,m;

void solve()
{
	vector<int> store(n+1);
	for(int i=0;i<n-1;i++)
		scanf("%d",&store[i]);
	store[n-1]=0,store[n]=d;

	sort(store.begin(),store.end());

	int ans=0;

	for(int i=0;i<m;i++)
	{
		int q;
		scanf("%d",&q);
		if(q!=0)
		{
			vector<int>::iterator it,jt;
			it=lower_bound(store.begin(),store.end(),q);

			jt=it;
			it--;

			ans+=min(q-(*it),(*jt)-q);
		}
	}

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d",&d);
		if(d==0)
			break;
		scanf("%d%d",&n,&m);

		solve();
	}
	return 0;
}

