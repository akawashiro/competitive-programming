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

int N,M;

void solve()
{
	int sugoroku[1000+1],me[1000+1];
	for(int i=1;i<=N;i++)
		scanf("%d",sugoroku+i);
	for(int i=1;i<=M;i++)
		scanf("%d",me+i);

	int ans=0,pos=1;
	while(1)
	{
		if(N<=pos)
			break;
		ans++;
		pos+=me[ans];

		if(N<=pos)
			break;
		pos+=sugoroku[pos];
	}

	printf("%d\n",ans);
}

int main()
{
	while(1)
	{
		scanf("%d%d",&N,&M);
		if(N==0 && M==0)
			break;
		solve();
	}
	return 0;
}

