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

int w,h;

void solve()
{
	int town[20][20];
	int n;
	memset(town,0,sizeof(town));

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		town[x][y]=-1;
	}

	town[1][1]=1;
	for(int x=1;x<=w;x++)
		for(int y=1;y<=h;y++)
			if(town[x][y]==-1)
				town[x][y]=0;
			else
				town[x][y]+=town[x-1][y]+town[x][y-1];
	printf("%d\n",town[w][h]);
}

int main()
{
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w==0 && h==0)
			break;
		solve();
	}
	return 0;
}

