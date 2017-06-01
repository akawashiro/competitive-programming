#include <stdio.h>
#include <string.h>
#define MOD 10000
int n;
int pl[200];
int dp[3][3][200];
int rec(int pp,int p,int k){
	if(k==n)	return dp[pp][p][k]=1;
	if(dp[pp][p][k]!=-1)	return dp[pp][p][k];
	if(2<=k&&p==pp&&p==pl[k])	return dp[pp][p][k]=0;
	if(pl[k]!=-1){
		return dp[pp][p][k]=rec(p,pl[k],k+1);
	}else{
		int r=0;
		for(int i=0;i<3;i++)
			if(!(2<=k&&p==pp&&p==i))
				r+=rec(p,i,k+1);
		return dp[pp][p][k]=r%MOD;
	}
}
int main(){
	int p;
	scanf("%d%d",&n,&p);
	memset(pl,-1,sizeof(pl));
	for(int i=0;i<p;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		pl[a]=b;
	}
	memset(dp,-1,sizeof(dp));
	int ans=rec(0,0,0);
	printf("%d\n",ans);
	return 0;
}

