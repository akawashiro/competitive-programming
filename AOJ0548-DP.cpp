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
int *DP[24];
int house[24][2];
int church;
int houseNum;
int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

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

	for(int i=0;i<24;i++)
	{
		DP[i]=(int*)malloc(sizeof(int)*(1<<houseNum));
		memset(DP[i],0,sizeof(DP[i]));
	}
	DP[church][0]=1;

	for(int state=0;state<(1<<houseNum);state++)
		for(int now=0;now<houseNum;now++)
		{
			if(!(state & (1<<now)))
				continue;

			for(int d=0;d<4;d++)
				for(int i=0;edge[now][d][i]!=-1;i++)
				{
					int e=edge[now][d][i];
					if( state & (1<<e) || (e==church && state==(1<<now)) )
					{
						DP[now][state]+=DP[e][state^(1<<now)];
						break;
					}
				}
		}

	printf("%d\n",DP[church][(1<<houseNum)-1]);

	for(int i=0;i<24;i++)
		free(DP[i]);
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

