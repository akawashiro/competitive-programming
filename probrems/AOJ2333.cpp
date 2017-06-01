//AOJ2333
#include <stdio.h>
#define MAX_N 300
#define MOD	  1000000007 
int w[MAX_N];
int dp[2][MAX_N][10000+1];
int main(){
	int n,W;
	scanf("%d%d",&n,&W);
	for(int i=0;i<n;i++)
		scanf("%d\n",w+i);
	w[n]=1<<30;
	for(int i=0;i<=n;i++)
		for(int j=0;j<10000+1;j++)
			dp[n%2][i][j]=j<w[i];
	for(int i=n-1;0<=i;i--)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=W;k++){
				int jj;
				if(w[j]<w[i])	jj=j;
				else			jj=i;
				dp[i%2][j][k]=0;
				if(0<=k-w[i])
					dp[i%2][j][k]+=dp[(i+1)%2][j][k-w[i]];
				dp[i%2][j][k]+=dp[(i+1)%2][jj][k];
				dp[i%2][j][k]%=MOD;
			}
	printf("%d\n",dp[0][n][W]);
	return 0;
}
				
