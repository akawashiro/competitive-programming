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

using namespace std;

int n;
char s,t,b;

void solve()
{
	s-='A';
	t-='A';
	b-='A';
	double room[5][5];

	for(int i=0;i<25;i++)
		room[i/5][i%5]=-2.0;
	for(int i=0;i<9;i++)
		room[i/3+1][i%3+1]=0.0;

	room[s/3+1][s%3+1]=1.0;
	room[b/3+1][b%3+1]=-2.0;

	for(int time=0;time<n;time++)
	{
		double pre[25][25];
		for(int i=0;i<25;i++)
			pre[i/5][i%5]=room[i/5][i%5];

		for(int pos=0;pos<9;pos++)
		{
			int x=pos%3+1,y=pos/3+1;
			if(pre[y][x]<-1.0)
				continue;

			double d=pre[y][x]/4.0;

			if(!(room[y+1][x]<-1.0))	room[y][x]-=d,room[y+1][x]+=d;
			if(!(room[y-1][x]<-1.0))	room[y][x]-=d,room[y-1][x]+=d;
			if(!(room[y][x+1]<-1.0))	room[y][x]-=d,room[y][x+1]+=d;
			if(!(room[y][x-1]<-1.0))	room[y][x]-=d,room[y][x-1]+=d;
		}
	}

	printf("%1.8lf\n",room[t/3+1][t%3+1]);
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		cin >> s >> t >> b;
		solve();
	}
	return 0;
}

