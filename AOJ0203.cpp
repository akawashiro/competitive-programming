//AOJ0203
#include <stdio.h>
#include <string.h>
int course[15][15];
int DP[16][15];
int main()
{
	while(1){
		int h,w;
		scanf("%d%d",&w,&h);
		if(!w&&!h)
			break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d",&course[i][j]);
		memset(DP,0,sizeof(DP));
		for(int x=0;x<w;x++)
			if(course[0][x]==0)
				DP[0][x]=1;
		for(int y=0;y<h-1;y++)
			for(int x=0;x<w;x++){
				if(course[y][x]==0){
					if(0<x&&course[y+1][x-1]!=2)
						DP[y+1][x-1]+=DP[y][x];
					DP[y+1][x]+=DP[y][x];
					if(x<w-1&&course[y+1][x+1]!=2)
						DP[y+1][x+1]+=DP[y][x];
				}else if(course[y][x]==1){
					DP[y][x]=0;
				}else{
					DP[y+2][x]+=DP[y][x];
				}
			}
		/*for(int i=0;i<=h;i++){
			for(int j=0;j<w;j++)
				printf("%d ",DP[i][j]);
			printf("\n");
		}
		printf("\n");*/
		int ans=0;
		for(int x=0;x<w;x++)
			if(course[h-1][x]!=1)
				ans+=DP[h-1][x];
		for(int x=0;x<w;x++)
			ans+=DP[h][x];
		printf("%d\n",ans);
	}
	return 0;
}

