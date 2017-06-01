//AOJ0156
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#define MAX_V 40000
#define INF 100000
using namespace std;
struct Edge{int to,cost;};
Edge makeE(int t,int c){Edge e;e.to=t;e.cost=c;return e;}
bool operator <(const Edge &e,const Edge &f){return e.cost>f.cost;}
vector<Edge> G[MAX_V];
int ma[200][200];
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};;
int dist[MAX_V];
int main(){
	while(1){
		int w,h;
		scanf("%d%d",&w,&h);
		if(!w&&!h)	break;
		for(int i=0;i<200;i++)for(int j=0;j<200;j++){
			ma[i][j]='.';
			G[i*200+j].clear();
			dist[i*200+j]=INF;
		}
		int goal;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				char c='\n';
				while(c=='\n')
					scanf("%c",&c);
				ma[i][j]=c;
				if(c=='&')
					goal=i*200+j;
			}
		/*for(int i=0;i<50;i++){
			for(int j=0;j<50;j++)
				printf("%c",ma[i][j]);
			printf("\n");
		}
		printf("\n");
		fflush(stdout);*/
		for(int i=0;i<200;i++)
			for(int j=0;j<200;j++)
				for(int k=0;k<4;k++){
					int ii=i+mv[k][0];
					int jj=j+mv[k][1];
					if(0<=ii&&ii<200&&0<=jj&&jj<200){
						int c=(ma[i][j]=='#'&&ma[ii][jj]!='#')?1:0;
						G[i*200+j].push_back(makeE(ii*200+jj,c));
					}
				}
		priority_queue<Edge> que;
		que.push(makeE(0,0));
		while(!que.empty()){
			int v=que.top().to;
			int d=que.top().cost;
			//printf("v=%d d=%d\n",v,d);
			que.pop();
			if(dist[v]<d)	continue;
			for(int i=0;i<(int)G[v].size();i++){
				//printf("G[v][i].to=%d\n",G[v][i].to);
				if(d+G[v][i].cost<dist[G[v][i].to]){
					dist[G[v][i].to]=d+G[v][i].cost;
					que.push(makeE(G[v][i].to,d+G[v][i].cost));
				}
			}
		}
		printf("%d\n",dist[goal]);
	}
	return 0;
}

