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

#define MAX_V 2002

struct Edge{ int to,cap,rev; };
int used[MAX_V];
vector<Edge> G[MAX_V];

void addEdge(int from,int to,int cap){
    G[from].push_back((Edge){to,cap,(int)G[to].size()});
    G[to].push_back((Edge){from,0,(int)G[from].size()-1});
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

int N,M,L;
int dist[100][100];

void solve(){
    memset(used,0,sizeof(used));
    vector<int> p,t;
    REP(i,MAX_V)G[i].clear();
    REP(i,100)REP(j,100)dist[i][j]=(1<<28);
    REP(i,100)dist[i][i]=0;
    REP(i,M){
        int u,v,d;
        cin>>u>>v>>d;
        dist[u][v]=dist[v][u]=d;
    }
    REP(k,N)
        REP(i,N)
            REP(j,N)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    REP(i,L){
        int pp,tt;
        cin>>pp>>tt;
        p.pb(pp);
        t.pb(tt);
    }
    REP(i,L)
        REP(j,L)
            if(i!=j&&t[i]+dist[p[i]][p[j]]<=t[j])
                addEdge(i,j+L,1);
    REP(i,L){
        addEdge(2*L,i,1);
        addEdge(i+L,2*L+1,1);
    }
    int r=maxFlow(2*L,2*L+1);
    cout<<L-r<<endl;
}

int main(void){
    while(1){
        cin>>N>>M>>L;
        if(N==0&&M==0&&L==0)
            break;
        solve();
    }
     return 0;
}
