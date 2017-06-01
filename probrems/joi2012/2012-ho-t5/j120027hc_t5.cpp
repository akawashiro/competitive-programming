#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX_V 100000+10
#define MAX_Q 100000+10
#define INF (1<<28)
#define ROOT 1
using namespace std;
struct Edge{
	int to,cost;
};
Edge makeE(int t,int c){
	Edge e;e.to=t,e.cost=c;
	return e;
}
bool operator < (const Edge &e,const Edge &f){
	return e.cost>f.cost;
}
struct Biedge{
	int a,b,cost;
};
Biedge makeB(int aa,int bb,int c){
	Biedge e;e.a=aa,e.b=bb,e.cost=c;
	return e;
}
bool operator < (const Biedge &e,const Biedge &f){
	return e.cost>f.cost;
}
class Unionfind{
	public:
		vector<int> data;
		Unionfind(int n){
			for(int i=0;i<n;i++)
				data.push_back(i);
		}
		int root(int a){
			//printf("root(%d)\n",a);
			if(data[a]==a)	return a;
			else		return data[a]=root(data[a]);
		}
		void set(int a,int b){
			if(root(a)==root(b))
				return;
			else
				data[root(a)]=root(b);
		}
};
int fest[MAX_V],dist[MAX_V],qa[MAX_Q],qb[MAX_Q],qr[MAX_Q],depth[MAX_V],score[32][MAX_V],parent[32][MAX_V];
vector<Biedge> biedge;
vector<Edge> G[MAX_V];
vector<Edge> MG[MAX_V];
void dfs(int v,int p,int s,int d){
	parent[0][v]=p;
	score[0][v]=s;
	depth[v]=d;
	for(int i=0;i<(int)MG[v].size();i++)
		if(MG[v][i].to!=p)
			dfs(MG[v][i].to,v,MG[v][i].cost,d+1);
}
void init(int n){
	dfs(ROOT,-1,dist[ROOT],0);
	for(int k=0;k+1<32;k++)
		for(int i=0;i<n;i++){
			if(parent[k][i]<0)	parent[k+1][i]=-1;
			else{
				score[k+1][i]=min(score[k][parent[k][i]],score[k][i]);
				parent[k+1][i]=parent[k][parent[k][i]];
			}
		}
}
int lca(int u,int v){
	int res=INF;
	if(depth[u]>depth[v])	swap(u,v);
	for(int k=0;k<32;k++)
		if((depth[v]-depth[u])>>k&1){
			res=min(res,score[k][v]);
			v=parent[k][v];
		}
	//printf("lca-m\n");fflush(stdout);
	if(u==v)	return res;
	for(int k=31;0<=k;k--)
		if(parent[k][u]!=parent[k][v]){
			res=min(res,score[k][u]);
			u=parent[k][u];
			res=min(res,score[k][v]);
			v=parent[k][v];
		}
	res=min(res,score[0][u]);
	res=min(res,score[0][v]);
	return res;
}
int main(){
	int n,m,k,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(makeE(b,c));
		G[b].push_back(makeE(a,c));
		biedge.push_back(makeB(a,b,0));
	}
	for(int i=0;i<k;i++)
		scanf("%d",fest+i);
	for(int i=0;i<q;i++)
		scanf("%d%d",qa+i,qb+i);
	for(int i=0;i<MAX_V;i++)
		dist[i]=INF;
	priority_queue<Edge> que;
	for(int i=0;i<k;i++){
		que.push(makeE(fest[i],0));
		dist[fest[i]]=0;
	}
	while(!que.empty()){
		int t=que.top().to,c=que.top().cost;
		que.pop();
		if(dist[t]<c)
			continue;
		for(int i=0;i<(int)G[t].size();i++){
			int tt=G[t][i].to,cc=c+G[t][i].cost;
			if(cc<dist[tt]){
				que.push(makeE(tt,cc));
				dist[tt]=cc;
			}
		}
	}
	for(int i=0;i<m;i++)
		biedge[i].cost=min(dist[biedge[i].a],dist[biedge[i].b]);
	sort(biedge.begin(),biedge.end());
	memset(qr,-1,sizeof(qr));
	Unionfind un(n+1);
	for(int i=0;i<m;i++){
		if(un.root(biedge[i].a)!=un.root(biedge[i].b)){
			un.set(biedge[i].a,biedge[i].b);
			MG[biedge[i].a].push_back(makeE(biedge[i].b,biedge[i].cost));
			MG[biedge[i].b].push_back(makeE(biedge[i].a,biedge[i].cost));
		}
	}
	init(n+1);
	for(int i=0;i<q;i++)
		printf("%d\n",lca(qa[i],qb[i]));
	return 0;
}

