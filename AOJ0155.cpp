//AOJ0155
#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#define MAX_V 1000
#define INF 25000000
using namespace std;
struct Edge{
	int to;
	double cost;
};
Edge makeE(int t,double c){
	Edge e;
	e.to=t;
	e.cost=c;
	return e;
}
struct Node{
	int v,p;
	double d;
};
Node makeN(int vv,int pp,double dd){
	Node n;
	n.v=vv,n.p=pp,n.d=dd;
	return n;
}
bool operator <(const Node &n,const Node &m){
	return (n.d>m.d);
}
vector<Edge> G[MAX_V];
int pr[MAX_V],x[MAX_V],y[MAX_V],b[MAX_V];
double di[MAX_V]; 
int main(){
	while(1){
		for(int i=0;i<MAX_V;i++)	G[i].clear();
		int n;
		scanf("%d",&n);
		if(!n)	break;
		for(int i=0;i<n;i++)	scanf("%d%d%d",b+i,x+i,y+i);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int xd=x[i]-x[j];
				int yd=y[i]-y[j];
				if(xd*xd+yd*yd<=2500){
					G[i].push_back(makeE(j,sqrt(xd*xd+yd*yd)));
					G[j].push_back(makeE(i,sqrt(xd*xd+yd*yd)));
				}
			}
		int m;
		scanf("%d",&m);
		for(;0<m;m--){
			int s,g;
			scanf("%d%d",&s,&g);
			for(int i=0;i<n;i++)
				if(b[i]==s){
					s=i;
					break;
				}
			for(int i=0;i<n;i++)
				if(b[i]==g){
					g=i;
					break;
				}
			for(int i=0;i<MAX_V;i++){
				di[i]=INF;
				pr[i]=-1;
			}
			priority_queue<Node> que;
			que.push(makeN(s,-1,0));
			while(!que.empty()){
				Node no=que.top();
				que.pop();
				if(di[no.v]<no.d)	continue;
				di[no.v]=no.d;
				pr[no.v]=no.p;
				for(int i=0;i<(int)G[no.v].size();i++){
					if(no.d+G[no.v][i].cost<di[G[no.v][i].to])
						que.push(makeN(G[no.v][i].to,no.v,no.d+G[no.v][i].cost));
				}
			}
			vector<int> v;
			while(g!=-1){
				v.push_back(b[g]);
				g=pr[g];
			}
			if(v.size()<2)
				printf("NA\n");
			else{
				for(int i=(int)v.size()-1;0<=i;i--){
					if(i!=(int)v.size()-1)
						printf(" ");
					printf("%d",v[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}


