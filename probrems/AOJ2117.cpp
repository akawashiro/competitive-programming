//AOJ2117
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define INF 10000000
using namespace std;
int n;
double x[14][2],y[14][2];
double dp[1<<14][14][2];
double dist(int i1,int s1,int i2,int s2){
	double xd=x[i1][s1]-x[i2][s2];
	double yd=y[i1][s1]-y[i2][s2];
	return sqrt(xd*xd+yd*yd);
}
double rec(int left,int k,int side){
	if(-0.5<dp[left][k][side])
		return dp[left][k][side];
	else if(left==(1<<k))
		return dp[left][k][side]=dist(k,side,k,(side+1)%2);
	else{
		double res=INF;
		left-=(1<<k);
		for(int i=0;i<n;i++)
			for(int s=0;s<2;s++)
				if(left&(1<<i))
					res=min(res,dist(k,side,k,(side+1)%2)+dist(k,(side+1)%2,i,s)+rec(left,i,s));
		return dp[left+(1<<k)][k][side]=res;
	}
}
int main(){
	for(int T=1;;T++){
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
		double ans=INF;
		for(int i=0;i<(1<<n);i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<2;k++)
					dp[i][j][k]=-1;
		for(int i=0;i<n;i++)
			for(int s=0;s<2;s++)
				ans=min(ans,rec((1<<n)-1,i,s));
		printf("Case %d: %lf\n",T,ans);
	}
	return 0;
}

