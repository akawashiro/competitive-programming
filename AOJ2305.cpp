//AOJ2305
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
static const int M = 200000;

int main()
{
	int N;
	cin >> N;
	int a[20];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	static double dp[20][M];
	for (int i = 0; i < N; i++) {
		fill_n(dp[i], M, 1e10);
	}
	/*for (int i = 1; i < M; i++) {
		dp[0][i] = fabs(a[0] - i)/double(a[0]);
	}*/
	for (int i = 0; i < N-1; i++) {
		for (int j = 1; j < M; j++) {
			if(i==0)
				dp[0][j]=fabs(a[0]-j)/double(a[0]);
			for (int k = 1; k*j < M; k++) {
				dp[i+1][k*j] = min(dp[i+1][k*j], max(dp[i][j], fabs(a[i+1] - k*j)/double(a[i+1])));
			}
		}
	}

	double ans = 1e10;
	for (int i = 1; i < M; i++) {
		ans = min(ans, dp[N-1][i]);
	}
	printf("%.9f\n", ans);
	return 0;
}

/*#include <stdio.h>
#include <float.h>
#include <algorithm>
#include <math.h>
#define M 200000
using namespace std;
int a[20];
double DP[20][M];
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d",a+i);
for(int i=0;i<n;i++)
for(int j=1;j<M;j++)
DP[i][j]=DBL_MAX;
for(int i=1;i<M;i++)
DP[0][i]=fabs(a[0]-i)/a[0];
for(int i=0;i<n-1;i++)
for(int j=1;j<M;j++)
for(int k=1;k*j<M;k++)
DP[i+1][k*j]=min(DP[i+1][k*j],max(DP[i][j],fabs(a[i+1]-k*j)/(double)a[i+1]));
double ans=DBL_MAX;
for(int i=1;i<M;i++)
ans=min(ans,DP[n-1][i]);
printf("%.9f\n",ans);
return 0;
}*/


