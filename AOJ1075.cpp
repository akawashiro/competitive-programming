//AOJ1075
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m;
int x[30],y[30],r[30],c[30],sc[900][2],up[30];
char dp[1<<24];
int rec(int left){
	if(dp[left]!=-1)	return dp[left];
	int res=n-__builtin_popcount(left);
	for(int i=0;i<m;i++){
		int a=sc[i][0],b=sc[i][1];
		if((left&(1<<a))&&((left&up[a])==0)&&(left&(1<<b))&&((left&up[b])==0))
				res=max(res,rec(left-(1<<a)-(1<<b)));
	}
	return dp[left]=res;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d",x+i,y+i,r+i,c+i);
		for(int i=0;i<n;i++){
			up[i]=0;
			for(int j=0;j<i;j++){
				int xd=x[i]-x[j],yd=y[i]-y[j],rs=r[i]+r[j];
				if(xd*xd+yd*yd<rs*rs)
					up[i]+=(1<<j);
			}
		}
		m=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(c[i]==c[j]){
					sc[m][0]=i,sc[m][1]=j;
					m++;
				}
		memset(dp,-1,sizeof(dp));
		int ans=rec((1<<n)-1);
		printf("%d\n",ans);
	}
	return 0;
}

