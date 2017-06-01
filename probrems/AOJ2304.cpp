//AOJ2304
#include <vector>
#include <stdio.h>
#include <limits.h>
#define MAX_V 1000
using namespace std;
struct Edge{ int to,cap,rev,num; };
int used[MAX_V];
vector<Edge> G[MAX_V];
void addEdge(int from,int to,int cap,int num){
	G[from].push_back((Edge){to,cap,G[to].size(),num});
	G[to].push_back((Edge){from,cap,G[from].size()-1,-num});
}
int DFS(int v,int t,int f){
	if(v==t)
		return f;
	used[v]=true;
	for(int i=0;i<(int)G[v].size();i++){
		Edge &e=G[v][i];
		if(!used[e.to] && 0<e.cap){
			int d=DFS(e.to,t,min(f,e.cap));
			if(0<d){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s,int t){
	int flow=0;
	while(1){
		for(int i=0;i<MAX_V;i++)
			used[i]=false;
		int f=DFS(s,t,INT_MAX);
		if(f==0)
			break;
		flow+=f;
	}
	return flow;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addEdge(a,b,1,i+1);
	}
	int S,T;
	scanf("%d%d",&S,&T);
	printf("%d\n",maxFlow(S,T));
	vector<int> v;
	for(int i=0;i<MAX_V;i++)
		for(int j=0;j<G[i].size();j++){
			//printf("from=%d to=%d cap=%d num=%d\n",i,G[i][j].to,G[i][j].cap,G[i][j].num);
			if(0<G[i][j].num&&G[i][j].cap==2&&G[G[i][j].to][G[i][j].rev].cap==0)
				v.push_back(G[i][j].num);
		}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)
		printf("%d\n",v[i]);
	return 0;
}

