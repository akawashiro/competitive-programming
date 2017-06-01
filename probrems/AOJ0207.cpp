#include <stdio.h>
#include <stack>
using namespace std;

int board[100][100];
int visit[100][100];
int main()
{
	while(1){
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				board[i][j]=0;
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				visit[i][j]=0;
		int h,w;
		scanf("%d%d",&w,&h);
		if(!h)
			break;
		int sy,sx,gy,gx;
		scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
		sy--,sx--,gy--,gx--;
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int c,d,x,y;
			scanf("%d%d%d%d",&c,&d,&x,&y);
			x--,y--;
			int ww=4,hh=2;
			if(d)
				swap(ww,hh);
			for(int yy=y;yy<y+hh;yy++)
				for(int xx=x;xx<x+ww;xx++)
					board[yy][xx]=c;
		}
		stack<int> yst,xst;
		yst.push(sy),xst.push(sx);
		int color=board[sy][sx];
		while(!yst.empty()){
			int y=yst.top();yst.pop();
			int x=xst.top();xst.pop();
			if(y<0||h<=y||x<0||w<=x||visit[y][x]||board[y][x]!=color)
				continue;
			visit[y][x]=1;
			yst.push(y+1),xst.push(x);
			yst.push(y-1),xst.push(x);
			yst.push(y),xst.push(x+1);
			yst.push(y),xst.push(x-1);
		}
		if(visit[gy][gx]&&color!=0)
			printf("OK\n");
		else
			printf("NG\n");
	}
	return 0;
}

