#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
int mv[2][6][2]={{{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}},{{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}}};
int bo[200][200];
int main(){
	int w,h;
	scanf("%d%d",&w,&h);
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			scanf("%d",&bo[i+2][j+2]);
	h+=4,w+=4;
	queue<pair<int,int> > qu;
	qu.push(make_pair(0,0));
	while(!qu.empty()){
		int y=qu.front().first;
		int x=qu.front().second;
		qu.pop();
		if(y<0||h<=y||x<0||w<=x||bo[y][x]!=0)
			continue;
		bo[y][x]=2;
		for(int i=0;i<6;i++){
			int yy=y+mv[y%2][i][0];
			int xx=x+mv[y%2][i][1];
			qu.push(make_pair(yy,xx));
		}
	}
	/*for(int y=0;y<h;y++){
		for(int x=0;x<w;x++)
			printf("%d ",bo[y][x]);
		printf("\n");
	}
	printf("\n");*/
	int ans=0;
	for(int y=0;y<h;y++)
		for(int x=0;x<w;x++)
			for(int i=0;i<6;i++){
				int yy=y+mv[y%2][i][0];
				int xx=x+mv[y%2][i][1];
				if(bo[y][x]==2&&0<=yy&&yy<h&&0<=xx&&xx<w&&bo[yy][xx]==1)
					ans++;
			}
	printf("%d\n",ans);
	return 0;
}

