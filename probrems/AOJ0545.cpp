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

int n,m;

void solve()
{
	int myFriend[501];
	memset(myFriend,0,sizeof(myFriend));
	myFriend[1]=2;

	vector<pair<int,int> > fr;
	for(int i=0;i<m;i++)
	{
		pair<int,int> p;
		scanf("%d%d",&p.first,&p.second);

		if(p.first==1)
			myFriend[p.second]=2;
		if(p.second==1)
			myFriend[p.first]=2;

		fr.push_back(p);
	}

	for(int i=0;i<m;i++)
	{
		int f=fr[i].first,s=fr[i].second;
		
		if(myFriend[f]==2 && myFriend[s]<2)
			myFriend[s]=1;
		if(myFriend[s]==2 && myFriend[f]<2)
			myFriend[f]=1;
	}

	int ans=0;
	for(int i=2;i<=n;i++)
		if(0<myFriend[i])
			ans++;

	printf("%d\n",ans);
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

