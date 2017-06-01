#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#define MAX_V 200000
#define MP map<int,pair<int,int> >
#define FI first
#define SE second
#define INF (1<<28)
using namespace std;
typedef long long ll;
ll dat[8*MAX_V];
void add(int a,int b,ll x,int k,int l,int r){
	//printf("add a=%d b=%d k=%d l=%d r=%d \n",a,b,k,l,r);
	if(b<=l||r<=a)
		;
	else{
		if(l<=a&&b<=r)
			dat[k]+=x;
		if(1<r-l){
			add(a,b,x,k*2+1,l,(l+r)/2);
			add(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
}
ll sum(int a,int b,int k,int l,int r){
	//printf("sum a=%d b=%d k=%d l=%d r=%d \n",a,b,k,l,r);
	if(a<=l&&r<=b){
		return dat[k];
	}else if(b<=l||r<=a){
		return 0;
	}else{
		return sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2,r);
	}
}
int n;
MP G[MAX_V];
int vdfs[MAX_V];
int depth[MAX_V];
int parent[32][MAX_V];
int dfs(int k,int b,int c,int d){
	//printf("dfs %d %d %d \n",k,b,c);
	vdfs[k]=c;
	depth[k]=d;
	parent[0][k]=b;
	for(MP::iterator i=G[k].begin();i!=G[k].end();i++)
		if((*i).FI!=b){
			(*i).SE.FI=c;
			c++;
			//printf("c = %d \n",c);
			c=dfs((*i).FI,k,c,d+1);
			(*i).SE.SE=c;
			c++;
			//printf("c = %d \n",c);
		}
	return c;
}
void lcaInit(){
	for(int k=1;k<30;k++)
		for(int i=1;i<=n;i++){
			if(parent[k-1][i]<0)
				parent[k][i]=-1;
			else
				parent[k][i]=parent[k-1][parent[k-1][i]];
		}
}
int lca(int u,int v){
	if(depth[u]>depth[v])
		swap(u,v);
	for(int k=0;k<20;k++)
		if((depth[v]-depth[u])>>k&1){
			v=parent[k][v];
		}
	if(u==v)
		return u;
	for(int k=28;0<=k;k--)
		if(parent[k][u]!=parent[k][v]){
			u=parent[k][u];
			v=parent[k][v];
		}
	return parent[0][u];
}
int edge[MAX_V*2][2];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b]=make_pair(-1,-1);
		G[b][a]=make_pair(-1,-1);
		edge[i+1][0]=a;
		edge[i+1][1]=b;
	}
	int N=dfs(1,-1,0,0)+1;
	lcaInit();
	//printf("N = %d \n",N);
	/*for(int i=1;i<=n;i++)
		printf("vdfs[%d] = %d depth[%d] = %d parent[0][%d] = %d parent[1][%d] = %d \n",i,vdfs[i],i,depth[i],i,parent[0][i],i,parent[1][i]);
	printf("\n");*/

	for(int i=1;i<=n;i++)
		for(MP::iterator j=G[i].begin();j!=G[i].end();j++)
			if(-1<(*j).SE.FI&&-1<(*j).SE.SE){
				//printf("add %d %d %d \n",(*j).SE.FI,(*j).SE.FI+1,1);
				//printf("add %d %d %d \n",(*j).SE.SE,(*j).SE.SE+1,-1);
				add((*j).SE.FI,(*j).SE.FI+1,1,0,0,N);
				add((*j).SE.SE,(*j).SE.SE+1,-1,0,0,N);
			}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int e,a,b;
			scanf("%d",&e);
			a=edge[e][0],b=edge[e][1];
			if(vdfs[a]>vdfs[b])
				swap(a,b);
			add(G[a][b].FI,G[a][b].FI+1,-INF,0,0,N);
			add(G[a][b].SE,G[a][b].SE+1,INF,0,0,N);
			add(G[a][b].FI,G[a][b].FI+1,1,0,0,N);
			add(G[a][b].SE,G[a][b].SE+1,-1,0,0,N);
		}else if(t==2){
			int e,a,b;
			scanf("%d",&e);
			a=edge[e][0],b=edge[e][1];
			if(vdfs[a]>vdfs[b])
				swap(a,b);
			add(G[a][b].FI,G[a][b].FI+1,-1,0,0,N);
			add(G[a][b].SE,G[a][b].SE+1,1,0,0,N);
			add(G[a][b].FI,G[a][b].FI+1,INF,0,0,N);
			add(G[a][b].SE,G[a][b].SE+1,-INF,0,0,N);
		}else{
			int a,b,c;
			scanf("%d%d",&a,&b);
			c=lca(a,b);
			//printf("lca a=%d b=%d c=%d\n",a,b,c);
			//printf("sum %d %d \n",vdfs[a],vdfs[b]+1);
			ll res=sum(vdfs[c],vdfs[a],0,0,N)+sum(vdfs[c],vdfs[b],0,0,N);
			if(INF/2<res)
				res=-1;
			cout<<res<<endl;
		}
	}
	return 0;
}

