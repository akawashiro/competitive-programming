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

int h,w;
int town[10][10];
int edge[24][4][24];
int house[24][2];
int church;
int houseNum;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
map<int,int> cache;

int rec(int now,int state,int left)
{
	if(now==church && state==0)
		return 1;
	if(left<9 && cache.find((state<<5)+now)!=cache.end())
		return cache[(state<<5)+now];

	int r=0;
	for(int d=0;d<4;d++)
	{
		int p=0;
		while(edge[now][d][p]!=-1)
		{
			int e=edge[now][d][p];

			if( state&(1<<e) || (e==church && state==(1<<now)) )
			{
				r+=rec(e,state^(1<<now),left-1);
				break;
			}

			p++;
		}
	}

	if(left<9)
		cache[(state<<5)+now]=r;

	return r;
}

void makeEdge()
{
	memset(edge,-1,sizeof(edge));
	for(int i=0;i<houseNum;i++)
	{
		int y=house[i][0],x=house[i][1];
		int yy,xx,p;

		for(int d=0;d<4;d++)
		{
			yy=y,xx=x,p=0;
			while(1)
			{
				yy+=mv[d][0],xx+=mv[d][1];
				if(yy<0 || h<=yy || xx<0 || w<=xx)
					break;
				if(town[yy][xx]!=-1)
				{
					edge[i][d][p]=town[yy][xx];
					p++;
				}
			}
		}
	}
}

void solve()
{
	houseNum=0;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			int a;
			scanf("%d",&a);
			if(a==0)
			{
				a=-1;
			}
			else
			{
				if(a==2)
					church=houseNum;
				house[houseNum][0]=i;
				house[houseNum][1]=j;
				a=houseNum;
				houseNum++;
			}
			town[i][j]=a;
		}

	makeEdge();

	cache.clear();
	int ans=rec(church,(1<<houseNum)-1,houseNum);

	printf("%d\n",ans);
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

