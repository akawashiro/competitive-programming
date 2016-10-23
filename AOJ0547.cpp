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

#define UP 0
#define LEFT 1

int w,h;

void solve()
{
	int DP[100+1][100+1][2];
	memset(DP,0,sizeof(DP));

	for(int y=1;y<=h;y++)
		for(int x=1;x<=w;x++)
		{
			if(y==1)
				DP[y][x][LEFT]=1;
			else
				DP[y][x][LEFT]=(DP[y][x-1][LEFT]+DP[y-1][x-1][UP])%100000;

			if(x==1)
				DP[y][x][UP]=1;
			else
				DP[y][x][UP]=(DP[y-1][x][UP]+DP[y-1][x-1][LEFT])%100000;
		}

	printf("%d\n",(DP[h][w][LEFT]+DP[h][w][UP])%100000);
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

