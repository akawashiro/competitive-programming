//AOJ1049
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,ans;
int ar[10][10];
int order[10],pos[10];
void dfs(int k){
	if(k==n-1){
		ans=min(ans,pos[k]);
		return;
	}else{
		int used=(1<<n)-1;
		for(int i=0;i<=k;i++)
			used-=1<<order[i];
		for(int next=0;next<n;next++)
			if(used&(1<<next)){
				order[k+1]=next;
				pos[k+1]=0;
				for(int i=k;0<=i&&pos[k+1]<ans;i--)
					pos[k+1]=max(pos[k+1],pos[i]+max(ar[order[i]][next],ar[next][order[i]]));
				if(pos[k+1]<ans)
					dfs(k+1);
			}
		return;
	}
}
int main(){
	while(1){
		if(scanf("%d",&n)==EOF||n==0)	break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&ar[i][j]);
		ans=1<<30;
		pos[0]=0;
		for(int i=0;i<n;i++){
			order[0]=i;
			dfs(0);
		}
		printf("%d\n",ans);
	}
	return 0;
}

