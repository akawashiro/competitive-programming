//AOJ1138
#include <stdio.h>
#include <vector>
using namespace std;
struct Edge{	int to;double cost;	};
Edge edge(int t,double c){	Edge e;e.to=t;e.cost=c;return e;	}
int n,goal;
int ticket[8];
vector<Edge> G[30];
double dp[1<<8][30];
double rec(int left,int k){
	if(0<=dp[left][k])	return dp[left][k];
	if(k==goal)	return dp[left][k]=0;
	double r=100000;
	for(int i=0;i<n;i++)
		if(left&(1<<i))
			for(int j=0;j<(int)G[k].size();j++)
				r=min(r,G[k][j].cost/ticket[i]+rec(left&(~(1<<i)),G[k][j].to));
	return dp[left][k]=r;
}
int main(){
	while(1){
		for(int i=0;i<30;i++){	G[i].clear();
			for(int j=0;j<1<<8;j++)	dp[j][i]=-1;
		}
		int m,p,start;
		scanf("%d%d%d%d%d",&n,&m,&p,&start,&goal);
		if(!n)	break;
		start--,goal--;
		for(int i=0;i<n;i++)
			scanf("%d",ticket+i);
		for(int i=0;i<p;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			G[a].push_back(edge(b,c));
			G[b].push_back(edge(a,c));
		}
		double ans=rec((1<<n)-1,start);
		if(100000<=ans)	printf("Impossible\n");
		else	printf("%lf\n",ans);
	}
	return 0;
}

