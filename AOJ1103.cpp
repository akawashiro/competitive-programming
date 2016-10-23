//AOJ1103
#include <stdio.h>
#include <string.h>
int rl[4][2];
int bo[4][4];
int dfs(int k){
	int y=k/4,x=k%4;
	if(y==4)	return 1;
	if(bo[y][x])	return dfs(k+1);
	int r=0;
	for(int i=0;i<4;i++){
		int yy=y+rl[i][0],xx=x+rl[i][1];
		if(0<=yy&&yy<4&&0<=xx&&xx<4&&!bo[yy][xx]){
			bo[y][x]=bo[yy][xx]=1;
			r+=dfs(k+1);
			bo[y][x]=bo[yy][xx]=0;
		}
	}
	return r;
}
int main(){
	while(1){
		for(int i=0;i<4;i++){
			int y,x;
			scanf("%d",&x);
			if(4<x)	return 0;
			scanf("%d",&y);
			if(y<0)	y=-y,x=-x;
			else if(y==0&&x<0)	x=-x;
			rl[i][0]=y,rl[i][1]=x;
		}
		memset(bo,0,sizeof(bo));
		int ans=dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

