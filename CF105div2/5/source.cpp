#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int ns[110];
int shelf[110][110];//sum
int dp[110][10010];
int tn,ti,ts;
int tar[110];
int tdp[110][110];
int rec(int l,int r){
	if(r<l)	return 0;
	if(tdp[l][r]!=-1)	return tdp[l][r];
	tdp[l][r]=min(tar[l]+rec(l+1,r),tar[r]+rec(l,r-1));
	shelf[ti][tn-(r-l+1)]=max(shelf[ti][tn-(r-l+1)],ts-tdp[l][r]);
	return tdp[l][r];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		ns[i]=a;
		ti=i,tn=a,ts=0;
		for(int j=0;j<a;j++)
			scanf("%d",tar+j),ts+=tar[j];
		memset(tdp,-1,sizeof(tdp));
		rec(0,tn-1);
		shelf[ti][tn]=ts;
		/*for(int i=0;i<=tn;i++)
			printf("shelf[%d][%d]=%d\n",ti,i,shelf[ti][i]);*/
	}
	for(int i=n-1;0<=i;i--)
		for(int j=0;j<=m;j++){
			for(int k=0;k<=ns[i]&&k<=j;k++)
				if(dp[i][j]<shelf[i][k]+dp[i+1][j-k])
					dp[i][j]=shelf[i][k]+dp[i+1][j-k];
			//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	printf("%d\n",dp[0][m]);
	return 0;
}
		
