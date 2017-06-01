//AOJ0131
#include <stdio.h>
#include <string.h>
int mv[5][2]={{-1,0},{0,-1},{0,0},{1,0},{0,1}};
int ans[10][10];
int sou[10][10];
int tmp[10][10];
int res[10][10];
int main(){
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				scanf("%d",&sou[i][j]);
		for(int m=0;m<(1<<10);m++){
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
					tmp[i][j]=sou[i][j];
			memset(res,0,sizeof(res));
			for(int x=0;x<10;x++)
				if(m&(1<<x)){
					res[0][x]=1;
					for(int i=0;i<5;i++){
						int yy=0+mv[i][0];
						int xx=x+mv[i][1];
						if(0<=yy&&yy<10&&0<=xx&&xx<10)
							tmp[yy][xx]=(tmp[yy][xx])?0:1;
					}
				}
			for(int y=1;y<10;y++)
				for(int x=0;x<10;x++)
					if(tmp[y-1][x]){
						res[y][x]=1;
						for(int i=0;i<5;i++){
							int yy=y+mv[i][0];
							int xx=x+mv[i][1];
							if(0<=yy&&yy<10&&0<=xx&&xx<10)
								tmp[yy][xx]=(tmp[yy][xx])?0:1;
						}
					}
			int c=0;
			for(int y=0;y<10;y++)
				for(int x=0;x<10;x++)
					if(tmp[y][x])
						c++;
			if(!c)
				for(int y=0;y<10;y++)
					for(int x=0;x<10;x++)
						ans[y][x]=res[y][x];
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(0<j)
					printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
