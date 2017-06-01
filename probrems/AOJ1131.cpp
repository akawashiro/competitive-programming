//AOJ1131
#include <stdio.h>
int a;
int dfs(int p,int q,int m,int n,int b){
	if(p==0)		return 1;
	int r=0;
	for(int i=b;i*m<=a;i++){
		int pp=p*i-q;
		int qq=q*i;
		if(0<n&&0<=pp)
			r+=dfs(pp,qq,i*m,n-1,i);
	}
	return r;
}
int main(){
	while(1){
		int p,q,n;
		scanf("%d%d%d%d",&p,&q,&a,&n);
		if(!p&&!q&&!a&&!n)	break;
		int ans=dfs(p,q,1,n,1);
		printf("%d\n",ans);
	}
	return 0;
}

