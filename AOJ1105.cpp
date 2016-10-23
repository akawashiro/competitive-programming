//AOJ1105
#include <stdio.h>
#include <string.h>
#define MAX_N 2000000
int dp[MAX_N];
int main(){
	while(1){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(!n&&!a&&!b)	break;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<=n;i++)
			if((0<=i-a&&dp[i-a])||(0<=i-b&&dp[i-b]))
				dp[i]=1;
		int ans=0;
		for(int i=0;i<=n;i++)
			if(!dp[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}

