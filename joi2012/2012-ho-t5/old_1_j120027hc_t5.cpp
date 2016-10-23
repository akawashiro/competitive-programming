#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX_V 100000+10
#define MAX_Q 100000+10
#define INF (1<<28)
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
int fest[MAX_V],dist[MAX_V],qa[MAX_Q],qb[MAX_Q],qr[MAX_Q];
vector<Biedge> biedge;
vector<Edge> G[MAX_V];
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
	/*for(int i=1;i<=n;i++)
		printf("dist[%d]=%d\n",i,dist[i]);
	fflush(stdout);*/
	for(int i=0;i<m;i++)
		biedge[i].cost=min(dist[biedge[i].a],dist[biedge[i].b]);
	sort(biedge.begin(),biedge.end());
	memset(qr,-1,sizeof(qr));
	Unionfind un(n+1);
	/*for(int j=1;j<=n;j++)
		printf("un.root(%d)=%d\n",j,un.root(j));*/
	for(int i=0;i<m;i++){
		if(un.root(biedge[i].a)!=un.root(biedge[i].b)){
			un.set(biedge[i].a,biedge[i].b);
			/*for(int j=1;j<=n;j++)
			  printf("un.root(%d)=%d\n",j,un.root(j));*/
			for(int j=0;j<q;j++)
				if(qr[j]==-1&&un.root(qa[j])==un.root(qb[j]))
					qr[j]=biedge[i].cost;
		}
	}
	for(int i=0;i<q;i++)
		printf("%d\n",qr[i]);
	return 0;
}
