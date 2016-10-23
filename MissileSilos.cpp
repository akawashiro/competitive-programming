//CF103div2MisslileSilos
#include <vector>
#include <queue>
#include <limits.h>
#include <stdio.h>
using namespace std;
class Edge{
	public:
		int to,cost;
		Edge(int t,int c){to=t;cost=c;}
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge> > Graph;
int n,s,l;
int ABS(int n){ return (n<0)?-n:n;	}
int dijkstra(Graph &G)
{
	int n=G.size(),ans=0;
	vector<int> dist(n,INT_MAX/2);
	priority_queue<Edge> que;
	que.push(Edge(s,0));
	dist[s]=0;
	while(!que.empty()){
		Edge e=que.top();
		que.pop();
		if(e.cost==dist[e.to]){
			dist[e.to]=e.cost;
			for(int i=0;i<(int)G[e.to].size();i++){
				int tt=G[e.to][i].to,cc=e.cost+G[e.to][i].cost;
				if(cc<dist[tt]){
					dist[tt]=cc;
					que.push(Edge(tt,cc));
				}
			}
		}
	}
	/*for(int i=1;i<n;i++)
		printf("dist[%d]=%d\n",i,dist[i]);*/
	for(int i=0;i<n;i++)
		if(dist[i]==l)
			ans++;
	int tmp=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<(int)G[i].size();j++){
			int t=G[i][j].to,c=G[i][j].cost;
			if(c==1)	continue;
			int rem=l-dist[i];
			if(!(0<rem&&rem<c))	continue;
			int via_t=(c-rem)+dist[t];
			if(via_t<l)	continue;
			if(l==via_t)	tmp++;
			else			ans++;
		}
	return ans+tmp/2;
}
int main(){
	int m;
	scanf("%d%d%d",&n,&m,&s);
	Graph G(n+1);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
	}
	scanf("%d",&l);
	printf("%d\n",dijkstra(G));
	return 0;
}

