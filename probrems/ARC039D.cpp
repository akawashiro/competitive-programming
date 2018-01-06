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
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
#define MAX_V 100000+10
#define MAX_LOG_V 32
typedef long long LL;
using namespace std;

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,int cost){
    g[from].push_back((Edge){to,cost});
}

void bridgeDfs(const Graph &g,int cur, int prev, vector<pair<int,int> > &brg, vector<vector<int> > &each_bcc, stack<int> &roots, stack<int> &S, vector<bool> &inS, vector<int> &order, int &k){

    // fprintf(stderr,"LINE=%d\n",__LINE__);
    order[cur] = ++k;
    S.push(cur); inS[cur] = true;
    roots.push(cur);

    for(int i=0;i<(int)g[cur].size();i++){
        int to = g[cur][i].to;
        if(order[to]==0){
            bridgeDfs(g,to,cur,brg,each_bcc,roots,S,inS,order,k);
        }
        else if(to!=prev && inS[to]){	//後退辺をたどる
            // fprintf(stderr,"LINE=%d\n",__LINE__);
            while(order[roots.top()] > order[to]) 
                roots.pop();	//cur〜toまで(toは含まない)の頂点をrootsから捨てる
        }
    }

    // fprintf(stderr,"LINE=%d\n",__LINE__);
    if(cur==roots.top()){
        if(prev!=-1)brg.push_back(pair<int,int>(prev,cur));
        vector<int> bcc;
        while(1){
            int node = S.top(); S.pop(); inS[node] = false;
            bcc.push_back(node);
            if(node==cur)break;
        }
        each_bcc.push_back(bcc);
        roots.pop();
    }

}

void bridge(const Graph &g,vector<pair<int,int>> &brg, vector<vector<int>> &each_bcc){
    vector<int> order(MAX_V);
    vector<bool> inS(MAX_V);
    stack<int> roots, S;
    int k=0;
    int N = g.size();
    for(int i=0;i<N;i++){
        if(order[i]==0){
            bridgeDfs(g,i,-1,brg,each_bcc,roots,S,inS,order,k);
        }
    }
}

// m is a map from old vertex in g to new vertex in h
void compressToTree(const Graph &g,const vector<vector<int>> &each_bcc,Graph &h,map<int,int> &m){
    int N = each_bcc.size();
    for(int i=0;i<N;i++){
        int M = each_bcc[i].size();
        for(int j=0;j<M;j++)
            m[each_bcc[i][j]] = i;
    }
    h = Graph(each_bcc.size());
    int L = g.size();
    for(int i=0;i<L;i++){
        for(auto e : g[i])
            if(m[i] != m[e.to]){
                addEdge(h,m[i],m[e.to],e.cost);
            }
    }
}

int parent[MAX_LOG_V][MAX_V];
int distData[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void lcaDfs(const Graph &g,int v,int p,int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0;i<(int)g[v].size();i++)
        if(g[v][i].to != p){
            distData[0][g[v][i].to] = g[v][i].cost;
            lcaDfs(g,g[v][i].to, v, d+1);
        }
}

void lcaInit(const Graph &g,int root){
    int N=g.size();
    lcaDfs(g,root,-1,0);

    for(int k=0;k+1<MAX_LOG_V;k++)
        for(int v=0;v<N;v++){
            if(parent[k][v]<0){
                distData[k+1][v]=distData[k][v];
                parent[k+1][v]=-1;
            }else{
                distData[k+1][v]=distData[k][parent[k][v]] + distData[k][v];
                parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
}

int lca(const Graph &g,int u,int v){
    if(depth[u]>depth[v])
        swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++)
        if((depth[v] - depth[u]) >> k & 1)
            v = parent[k][v];
    if(u == v)
        return u;
    for(int k=MAX_LOG_V-1;0<=k;k--)
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    return parent[0][u];
}

int dist(const Graph &g,int u,int v){
    int r=0;
    if(depth[u]>depth[v])
        swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++)
        if((depth[v] - depth[u]) >> k & 1){
            r += distData[k][v];
            v = parent[k][v];
        }
    if(u == v)
        return r;
    for(int k=MAX_LOG_V-1;0<=k;k--)
        if(parent[k][u] != parent[k][v]){
            r += distData[k][u];
            r += distData[k][v];
            u = parent[k][u];
            v = parent[k][v];
        }
    return (r + distData[0][u] + distData[0][v]);
}


int main(void){
    int N,M;GI(N);GI(M);
    Graph g(N);
    REP(i,M){
        int X,Y;GI(X);GI(Y);X--;Y--;
        addEdge(g,X,Y,1);
        addEdge(g,Y,X,1);
    }
    vector<pair<int,int>> brg;
    vector<vector<int>> each_bcc;
    if(N != M+1){
        bridge(g,brg,each_bcc);
        Graph h;
        map<int,int> m;
        compressToTree(g,each_bcc,h,m);
        lcaInit(h,m[0]);
        int Q;GI(Q);
        REP(i,Q){
            int A,B,C;GI(A);GI(B);GI(C);A--;B--;C--;A=m[A];B=m[B];C=m[C];
            if(dist(h,A,B) + dist(h,B,C) == dist(h,A,C))
                printf("OK\n");
            else
                printf("NG\n");
        }
    }else{
        lcaInit(g,0);
        int Q;GI(Q);
        REP(i,Q){
            int A,B,C;GI(A);GI(B);GI(C);A--;B--;C--;
            if(dist(g,A,B) + dist(g,B,C) == dist(g,A,C))
                printf("OK\n");
            else
                printf("NG\n");
        }

    }
    return 0;
}

