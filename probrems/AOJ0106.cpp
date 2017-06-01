//AOJ0106
#include <stdio.h>
#define INF 1000000
int dp[100];
int gr[6]={2,3,5,10,12,15};
int pr[6]={380,550,850,1520,1870,2244};
int main(){
	for(int i=0;i<100;i++) 
		dp[i]=INF;
	dp[0]=0;
	for(int i=2;i<100;i++)
		for(int j=0;j<6;j++)
			if(0<=i-gr[j]&&dp[i-gr[j]]+pr[j]<dp[i])
				dp[i]=dp[i-gr[j]]+pr[j];
	while(1){
		int n,ans=INF;
		scanf("%d",&n);
		if(!n)	break;
		n/=100;
		/*for(int i=n;i<100;i++)
		  if(dp[i]<ans)
		  ans=dp[i];*/
		ans=dp[n];
		printf("%d\n",ans);
	}
	return 0;
}

