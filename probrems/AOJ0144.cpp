//AOJ0144
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int G[101][101];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=10000;
	for(int i=1;i<=n;i++)
		G[i][i]=0;
	for(int i=0;i<n;i++){
		int r,k;
		scanf("%d%d",&r,&k);
		for(int j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			G[r][t]=1;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	int p;
	scanf("%d",&p);
	for(int i=0;i<p;i++){
		int s,d,v;
		scanf("%d%d%d",&s,&d,&v);
		if(G[s][d]+1<=v)
			printf("%d\n",G[s][d]+1);
		else
			printf("NA\n");
	}
	return 0;
}

