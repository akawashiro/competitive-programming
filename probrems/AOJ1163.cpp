//AOJ1163
#include <vector>
#include <stdio.h>
#include <limits.h>
#define MAX_V 2000
using namespace std;
struct Edge{ int to,cap,rev; };
int used[MAX_V];
vector<Edge> G[MAX_V];
void addEdge(int from,int to,int cap){
	G[from].push_back((Edge){to,cap,G[to].size()});
	G[to].push_back((Edge){from,0,G[from].size()-1});
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
int gcd(int x,int y){
	if(y==0)	return x;
	else	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}

int b[500],r[500];
int main(){
	while(1){
		for(int i=0;i<MAX_V;i++)	G[i].clear();
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n&&!m)	break;
		for(int i=0;i<n;i++)
			scanf("%d",b+i);
		for(int i=0;i<m;i++)
			scanf("%d",r+i);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(gcd(b[i],r[j])!=1)
					addEdge(i,n+j,1);
		for(int i=0;i<n;i++)
			addEdge(n+m,i,1);
		for(int i=n;i<n+m;i++)
			addEdge(i,n+m+1,1);
		printf("%d\n",maxFlow(n+m,n+m+1));
	}
	return 0;
}

