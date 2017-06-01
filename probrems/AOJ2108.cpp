//AOJ2108
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 300
int n;
int G[50][50];
int DP[50][50][INF];
int DFS(int a,int b,int turn){
	int &res=DP[a][b][turn];
	if(a==b)	return turn;
	else if(0<=res)	return res;
	else if(turn==INF-1)	return res=INF;
	else if(turn%2==0){
		res=0;
		for(int i=0;i<n;i++)
			if(G[a][i])
				res=max(res,DFS(i,b,turn+1));
		return res;
	}else{
		res=INF;
		for(int i=0;i<n;i++)
			if(G[b][i])
				res=min(res,DFS(a,i,turn+1));
		return res;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(;0<T;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&G[i][j]);
		for(int i=0;i<n;i++)
			G[i][i]=1;
		memset(DP,-1,sizeof(DP));
		int a,b,ans;
		scanf("%d%d",&a,&b);
		ans=DFS(a,b,0);
		if(ans>=INF)
			printf("infinity\n");
		else
			printf("%d\n",ans/2);
	}
	return 0;
}

