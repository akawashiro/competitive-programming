//AOJ1156
#include <stdio.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define INF (1<<28)
struct Data{int c,y,x,d;};
Data makeD(int cc,int yy,int xx,int dd){Data n;n.c=cc,n.y=yy,n.x=xx,n.d=dd;
	return n;
}
bool operator < (const Data &d,const Data &e){
	return d.c>e.c;
}
int cost[4];
int mv[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int board[30][30];
int dist[30][30][4];
int main()
{
	while(1){
		int w,h;
		scanf("%d%d",&w,&h);
		if(w==0&&h==0)	break;
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)scanf("%d",&board[i][j]);
		for(int i=0;i<4;i++)scanf("%d",cost+i);
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)for(int k=0;k<4;k++)
			dist[i][j][k]=INF;
		priority_queue<Data> que;
		que.push(makeD(0,0,0,1));
		dist[0][0][1]=0;
		while(!que.empty()){
			Data d=que.top();que.pop();
			if(dist[d.y][d.x][d.d]<d.c)	continue;
			//printf("d.c=%d d.y=%d d.x=%d d.d=%d\n",d.c,d.y,d.x,d.d);
			Data dd;
			if(board[d.y][d.x]==0){
				dd.c=d.c;dd.d=(d.d+0)%4;
				dd.y=d.y+mv[dd.d][0];dd.x=d.x+mv[dd.d][1];
			}else if(board[d.y][d.x]==1){
				dd.c=d.c;dd.d=(d.d+1)%4;
				dd.y=d.y+mv[dd.d][0];dd.x=d.x+mv[dd.d][1];
			}else if(board[d.y][d.x]==2){
				dd.c=d.c;dd.d=(d.d+2)%4;
				dd.y=d.y+mv[dd.d][0];dd.x=d.x+mv[dd.d][1];
			}else if(board[d.y][d.x]==3){
				dd.c=d.c;dd.d=(d.d+3)%4;
				dd.y=d.y+mv[dd.d][0];dd.x=d.x+mv[dd.d][1];
			}else{
				dd=d;
			}
			if(0<=dd.y&&dd.y<h&&0<=dd.x&&dd.x<w&&dd.c<dist[dd.y][dd.x][dd.d]){
				dist[dd.y][dd.x][dd.d]=dd.c;
				que.push(dd);
			}
			for(int i=0;i<4;i++){
				dd.c=d.c+cost[i];dd.d=(d.d+i)%4;
				dd.y=d.y+mv[dd.d][0];dd.x=d.x+mv[dd.d][1];
				if(0<=dd.y&&dd.y<h&&0<=dd.x&&dd.x<w&&dd.c<dist[dd.y][dd.x][dd.d]){
					dist[dd.y][dd.x][dd.d]=dd.c;
					que.push(dd);
				}
			}
		}
		int ans=INF;
		for(int i=0;i<4;i++)	ans=min(ans,dist[h-1][w-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
