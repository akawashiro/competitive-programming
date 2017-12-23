#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define get0(x)     (get<0>(x))
#define get1(x)     (get<1>(x))
#define get2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807LL
#define LLMIN       -9223372036854775808LL
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;
using namespace std;

#define MAX_V 100000+1

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
vector<Edge> G[MAX_V];
vector<int> dist(MAX_V,INT_MAX/2);
int N;

void addEdge(int from,int to,int cost){
    G[from].push_back((Edge){to,cost});
}

int dijkstra(vector<int> s,int g)
{
    priority_queue<Edge> que;
    for(int ss : s)
        que.push(Edge{ss,0});
    while(!que.empty()){
        Edge e=que.top();
        que.pop();
        if(e.cost<dist[e.to]){
            dist[e.to]=e.cost;
            for(int i=0;i<(int)G[e.to].size();i++)
                que.push(Edge{G[e.to][i].to,e.cost+G[e.to][i].cost});
        }
    }
    return dist[g];
}


#define MAX_LOG_V 32

int root=0;

int parent[MAX_LOG_V][MAX_V];
int maxCost[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v,int p,int d){
    parent[0][v] = p;
    for(auto e : G[v])
        if(e.to == p)
            maxCost[0][v] = e.cost;
    depth[v] = d;
    for(int i=0;i<G[v].size();i++)
        if(G[v][i].to != p)
            dfs(G[v][i].to, v, d+1);
    // printf("v=%d p=%d d=%d\n",v,p,d);
}

void init(){
    // printf("\n");
    dfs(root,-1,0);

    for(int k=0;k+1<MAX_LOG_V;k++)
        for(int v=0;v<N;v++){
            if(parent[k][v]<0)
                parent[k+1][v]=-1;
            else{
                maxCost[k+1][v]=min(maxCost[k][v],maxCost[k][parent[k][v]]);
                parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
}

int lca(int u,int v){
    // printf("\n");
    int r=INT_MAX;
    // printf("u=%d v=%d r=%d d[u]=%d d[v]=%d\n",u,v,r,depth[u],depth[v]);
    if(depth[u]>depth[v])
        swap(u,v);
    for(int k=0;k<N;k++)
        if((depth[v] - depth[u]) >> k & 1){
            r = min(r,maxCost[k][v]);
            v = parent[k][v];
            // printf("u=%d v=%d r=%d\n",u,v,r);
        }
    if(u == v)
        return r;
    for(int k=MAX_LOG_V-1;0<=k;k--)
        if(parent[k][u] != parent[k][v]){
            r = min(r,maxCost[k][u]);
            r = min(r,maxCost[k][v]);
            u = parent[k][u];
            v = parent[k][v];
            // printf("u=%d v=%d r=%d\n",u,v,r);
        }
    r = min(r,maxCost[0][u]);
    return r;
}

class UnionFind
{
    vector<int> data;
    vector<int> scale;
    public:
    UnionFind(int n)
    {
        for(int i=0;i<n;i++)
        {
            data.push_back(i);
            scale.push_back(1);
        }
    }
    int root(int n)
    {
        if(data[n]==n)
            return n;
        else
            return data[n]=root(data[n]);
    }
    void set(int x,int y)
    {
        if(root(x)==root(y))
            return;
        scale[root(y)]+=scale[root(x)];
        scale[root(x)]=0;
        data[root(x)]=data[root(y)];
    }
    int size(int n)
    {
        return scale[root(n)];
    }
};

int M,K,Q;
vector<int> A,B;

int main(void){
    GI(N);GI(M);GI(K);GI(Q);
    REP(i,M){
        int a,b,l;
        GI(a);GI(b);GI(l);a--;b--;
        addEdge(a,b,l);
        addEdge(b,a,l);
        A.pb(a);
        B.pb(b);
    }
    vector<int> fes;
    REP(i,K){
        int a;
        GI(a);a--;
        fes.pb(a);
    }
    dijkstra(fes, N-1);
    REP(i,N)
        G[i].clear();
    vector<tuple<int,int,int> > vt;
    REP(i,M)
        vt.pb(mt(min(dist[A[i]],dist[B[i]]),A[i],B[i]));
    sort(ALL(vt));
    reverse(ALL(vt));
    UnionFind U(N);
    for(auto t : vt){
        int a = get1(t), b = get2(t), c = get0(t);
        if(U.root(a) != U.root(b)){
            U.set(a,b);
            addEdge(a,b,c);
            addEdge(b,a,c);
            // printf("a=%d b=%d c=%d\n",a,b,c);
        }
    }
    init();
    REP(i, Q){
        int a,b;
        GI(a);GI(b);a--;b--;
        printf("%d\n",lca(a,b));
    }
    return 0;
}
