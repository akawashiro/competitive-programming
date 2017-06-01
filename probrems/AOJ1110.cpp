//AOJ1110
#include <stdio.h>
#include <string.h>
using namespace std;
int cards[20];
int mv[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int dp[1<<20];
int rec(int left){
	if(dp[left]!=-1)	return dp[left];
	int n=0;
	int bo[5][4];
	memset(bo,-1,sizeof(bo));
	for(int i=0;i<20;i++)
		if(left&(1<<i)){
			bo[n/4][n%4]=i;
			n++;
		}
	int res=n;
	for(int i=0;i<n;i++){
		int y=i/4,x=i%4;
		for(int j=0;j<8;j++){
			int yy=y+mv[j][0];
			int xx=x+mv[j][1];
			if(0<=yy&&yy<5&&0<=xx&&xx<4&&bo[yy][xx]!=-1
					&&cards[bo[y][x]]==cards[bo[yy][xx]]){
				res=min(res,rec(left-(1<<bo[y][x])-(1<<bo[yy][xx])));
			}
		}
	}
	return dp[left]=res;
}
int main(){
	int T;scanf("%d",&T);
	for(;0<T;T--){
		for(int i=0;i<20;i++)
			scanf("%d",cards+i);
		memset(dp,-1,sizeof(dp));
		int ans=rec((1<<20)-1);
		printf("%d\n",ans);
	}
	return 0;
}
	
