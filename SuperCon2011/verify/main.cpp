#include <stdio.h>
#include <deque>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <queue>

using namespace std;

int k,w,h;
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int D[200+1][200+1][4];
int cache[210][210][300];

int rec(int x,int y,int c)
{
	//printf("rec x=%d y=%d c=%d\n",x,y,c);

	int &r=cache[x][y][c];
	if(r!=-1)
		;
	else if(x==0 && y==0 && c==0)
		r=1;
	else
	{
		r=0;
		for(int i=0;i<4;i++)
			if(D[x][y][i]!=0)
			{
				int xx=x+mv[i][0],yy=y+mv[i][1];
				int cc=c-D[x][y][i];
				if(0<=cc)
					r+=rec(xx,yy,cc);
			}
	}
	return r;
}

void solve(int _h,int _w,int _k,int _D[200+1][200+1][4],int *ans_len,int *ans_num)
{
	//printf("solve()-start\n");

	k=_k,w=_w,h=_h;
	h++,w++;
	for(int p=0;p<201;p++)
		for(int q=0;q<201;q++)
			for(int r=0;r<4;r++)
				D[p][q][r]=_D[p][q][r];
	memset(cache,-1,sizeof(cache));
	//printf("dist[%d][%d][%d]=%d\n",w-1,h-1,k-1,dist[w-1][h-1][k-1]);
	//printf("kCost=%d kWay=%d\n",kCost,kWay);
	*ans_len=-1;
	*ans_num=-1;
	int o=0;
	for(int i=0;i<300;i++)
	{
		int a=rec(w-1,h-1,i);
		if(a!=0)
		{
			//printf("c=%d ways=%d\n",i,a);
			o++;
			if(o==k)
			{
				*ans_len=i;
				*ans_num=a;
			}
		}
	}
	if(*ans_len==-1)
	{
		*ans_len=0;
		*ans_num=0;
	}
	
	//printf("solve()-end\n");
}

