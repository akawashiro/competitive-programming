//AOJ1162
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
#define MAX_V 35
#define MAX_S 35
#define INF 1000000
#define EPS 1e-10
using namespace std;
//int to[MAX_V][MAX_V];
int limit[MAX_V][MAX_V];
double dist[MAX_V][MAX_V];
int visited[MAX_V][MAX_V][MAX_S];
double ans[MAX_V][MAX_V][MAX_S];
struct Node{	int to,from,speed;double cost;	};
Node makeN(int t,int f,int s,double c){
	Node n;
	n.to=t;n.from=f;n.speed=s;n.cost=c;
	return n;
}
bool operator < (const Node &n,const Node &m){
	return n.cost>m.cost;
}
int main(){
	while(1){
		for(int i=0;i<MAX_V;i++)
			for(int j=0;j<MAX_V;j++){
				//to[i][j]=INF;
				dist[i][j]=INF;
				limit[i][j]=INF;
			}
		for(int i=0;i<MAX_V;i++)
			for(int j=0;j<MAX_V;j++)
				for(int k=0;k<MAX_S;k++)
					ans[i][j][k]=INF;
		memset(visited,0,sizeof(visited));
		int n,m,S,G;
		scanf("%d%d",&n,&m);
		if(!n&&!m)	break;
		scanf("%d%d",&S,&G);
		S--,G--;
		for(int i=0;i<m;i++){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a--,b--;
			dist[a][b]=dist[b][a]=c;
			limit[a][b]=limit[b][a]=d;
		}
		double res=INF;
		priority_queue<Node> que;
		//que.push(makeN(S,0,0,0));
		for(int i=0;i<n;i++)
			if(dist[S][i]!=INF){
				que.push(makeN(i,S,1,dist[S][i]));
				ans[i][S][1]=dist[S][i];
			}
		while(!que.empty()){
			int t=que.top().to,f=que.top().from,s=que.top().speed;
			double c=que.top().cost;
			//printf("t=%d f=%d s=%d c=%lf\n",t,f,s,c);
			que.pop();
			if(visited[t][f][s])	continue;
			visited[t][f][s]=1;
			if(t==G&&s==1){
				res=c;
				break;
			}
			for(int i=0;i<n;i++)
				if(i!=f&&dist[t][i]!=INF)
					for(int j=-1;j<=1;j++){
						int ss=s+j;
						if(0<ss&&ss<=limit[t][i]){
							int tt=i,ff=t;
							double cc=c+dist[t][i]/ss;
							if(cc<ans[tt][ff][ss]){
								que.push(makeN(tt,ff,ss,cc));
								ans[tt][ff][ss]=cc;
							}
						}
					}
		}
		if(res==INF)	printf("unreachable\n");
		else			printf("%lf\n",res);
	}
	return 0;
}

