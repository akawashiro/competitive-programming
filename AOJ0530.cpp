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
int stoneSize;
LL cache[2000][100];
LL stone[2000][3];

LL ABS(LL num)
{
	if(num<0)
		num*=-1;
	return num;
}

LL slipness(int s,int e)
{
	if(s==0 || e==stoneSize)
		return 0;
	else
		return (stone[s][2]+stone[e][2])*ABS(stone[s][1]-stone[e][1]);
}

LL rec(int pos,int m)
{
	if(pos==stoneSize)
		return cache[pos][m]=0;
	if(cache[pos][m]!=-1)
		return cache[pos][m];

	LL r=(1<<30);

	for(int i=pos+1;i<=stoneSize && stone[i][0]<=stone[pos][0]+1;i++)
		if(stone[pos][0]+1==stone[i][0])
			r=min(r,slipness(pos,i)+rec(i,m));

	if(0<m)
		for(int i=pos+1;i<=stoneSize && stone[i][0]<=stone[pos][0]+2;i++)
			if(stone[pos][0]+2==stone[i][0])
				r=min(r,slipness(pos,i)+rec(i,m-1));

	return cache[pos][m]=r;
}

void solve()
{
	memset(cache,-1,sizeof(cache));
	memset(stone,-1,sizeof(stone));

	stone[0][0]=0;
	stoneSize=1;

	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			int x,d;
			scanf("%d%d",&x,&d);
			stone[stoneSize][0]=i;
			stone[stoneSize][1]=x;
			stone[stoneSize][2]=d;
			stoneSize++;
		}
	}
	stone[stoneSize][0]=n+1;

	LL ans=rec(0,m);
	printf("%lld\n",ans);
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
	//scanf("%d%d",&n,&m);
	//solve();
	return 0;
}

