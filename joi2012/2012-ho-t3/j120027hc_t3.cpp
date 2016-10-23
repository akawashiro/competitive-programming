#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,S,T;
int A[3010],B[3010];
int dp[3010][3010];
int rec(int store,int time){
	if(store==n)
		return 0;
	else if(dp[store][time]!=-1)
		return dp[store][time];
	else{
		int res=rec(store+1,time);
		if(time<S&&S<time+B[store]){
			if(S+B[store]<=T){
				res=max(res,rec(store+1,S+B[store])+A[store]);
			}
		}else{
			if(time+B[store]<=T){
				res=max(res,rec(store+1,time+B[store])+A[store]);
			}
		}
		return dp[store][time]=res;
	}
}
int main(){
	scanf("%d%d%d",&n,&T,&S);
	for(int i=0;i<n;i++)
		scanf("%d%d",A+i,B+i);
	memset(dp,-1,sizeof(dp));
	int ans=rec(0,0);
	printf("%d\n",ans);
	return 0;
}

