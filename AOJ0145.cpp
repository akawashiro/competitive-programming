//AOJ0145
#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long LL;
LL a[100],b[100];
LL dp[100][100];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld%lld",a+i,b+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=INT_MAX;
	for(int i=0;i<n;i++)
		dp[i][i]=0;
	for(int j=1;j<n;j++)
		for(int i=0;i+j<n;i++)
			for(int k=i;k<i+j;k++)
				dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+a[i]*b[k]*a[k+1]*b[i+j]);
	printf("%lld\n",dp[0][n-1]);
	return 0;
}

