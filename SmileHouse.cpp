//Codeforces Testing Round #4
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define INF (1<<28)
int n;
int G[10][300][300];
int g[300][300],tmp[300][300];
int isCycle(int g[][300]){
	for(int i=0;i<n;i++)if(0<g[i][i])return 1;
	return 0;
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)G[0][i][j]=-INF;
	for(int i=0;i<n;i++)G[0][i][i]=0;
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--,b--;
		G[0][a][b]=c;
		G[0][b][a]=d;
	}
	for(int i=1;i<10;i++){
		for(int j=0;j<n;j++)for(int k=0;k<n;k++)G[i][j][k]=G[i-1][j][k];
		for(int l=0;l<n;l++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)
			G[i][j][k]=max(G[i][j][k],G[i-1][j][l]+G[i-1][l][k]);
	}
	int bo=-1,ce;
	for(int i=0;i<9;i++){
		if(!isCycle(G[i])&&isCycle(G[i+1])){
			bo=pow(2,i);ce=pow(2,i+1);
			for(int j=0;j<n;j++)for(int k=0;k<n;k++)g[j][k]=G[i][j][k];
		}
	}
	if(bo==-1){
		printf("0\n");return 0;
	}
	while(1<ce-bo){
		int e=0;
		while(pow(2,e)*2!=ce-bo)	e++;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)tmp[i][j]=g[i][j];
		for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
			tmp[i][j]=max(tmp[i][j],g[i][k]+G[e][k][j]);
		if(isCycle(tmp))	ce=bo+pow(2,e);
		else{
			bo=bo+pow(2,e);
			for(int i=0;i<n;i++)for(int j=0;j<n;j++)g[i][j]=tmp[i][j];
		}
	}
	if(isCycle(g))	printf("%d\n",bo);
	else			printf("%d\n",ce);
	return 0;
}

