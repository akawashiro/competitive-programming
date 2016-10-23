//AOJ2249
#include <queue>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
using namespace std;
class Edge{
	public:
		int v,d,c;
		Edge(int vv,int dd,int cc){	v=vv,d=dd,c=cc;	};
		bool operator<(const Edge &e)const{
			if(d!=e.d)	return d>e.d;
			else		return c>e.c;
		}
};
int main(){
	while(1){
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n&&!m)	break;
		vector<vector<Edge> > G(n);
		vector<int> dist(n,INT_MAX/2);
		priority_queue<Edge> qu;
		for(int i=0;i<m;i++){
			int u,v,d,c;
			scanf("%d%d%d%d",&u,&v,&d,&c);
			u--,v--;
			G[u].push_back(Edge(v,d,c));
			G[v].push_back(Edge(u,d,c));
		}
		int ans=0;
		qu.push(Edge(0,0,0));
		while(!qu.empty()){
			Edge e=qu.top();
			qu.pop();
			if(dist[e.v]<=e.d)	continue;
			dist[e.v]=e.d;
			ans+=e.c;
			for(int i=0;i<G[e.v].size();i++)
				qu.push(Edge(G[e.v][i].v,e.d+G[e.v][i].d,G[e.v][i].c));
		}
		printf("%d\n",ans);
	}
	return 0;
}

