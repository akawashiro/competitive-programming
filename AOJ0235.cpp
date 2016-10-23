//AOJ0235
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int cache[20][2];
int E[20];
int G[20][20];
int rec(int b,int k,int f)
{
	if(cache[k][f]!=-1)
		return cache[k][f];
	if(f==0){
		int r=5000*20;
		for(int i=0;i<n;i++){
			int a=0;
			for(int j=0;j<n;j++)
				if(j!=b&&E[j]!=1&&G[k][j]!=-1){
					if(i==j)
						a+=rec(k,j,0)+G[k][j];
					else
						a+=rec(k,j,1)+G[k][j]*2;
				}
			r=min(a,r);
		}
		return cache[k][f]=r;
	}else{
		int r=0;
		for(int i=0;i<n;i++)
			if(i!=b&&E[i]!=1&&G[k][i]!=-1)
				r+=rec(k,i,1)+G[k][i]*2;
		return cache[k][f]=r;
	}
}
int main()
{
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		memset(G,-1,sizeof(G));
		memset(E,0,sizeof(E));
		for(int i=0;i<n-1;i++){
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			G[a-1][b-1]=G[b-1][a-1]=t;
			E[a-1]++,E[b-1]++;
		}
		memset(cache,-1,sizeof(cache));
		int ans=rec(20,0,0);
		printf("%d\n",ans);
	}
	return 0;
}

