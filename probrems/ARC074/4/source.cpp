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
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807
#define LLMIN       -9223372036854775808
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;

using namespace std;


#define MAX_V 200000

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
        if(f==0) return flow;
        flow+=f;
    }
}

int main(void){
    int H,W;
    vector<string> vs;
    cin>>H>>W;
    REP(i,H){
        string s;cin>>s;vs.pb(s);}
    int sy,sx,ty,tx;
    REP(i,H)
        REP(j,W){
            if(vs[i][j]=='S'){
                sy=i,sx=j;
                addEdge(i*W+j,H*W+j,INT_MAX);
                addEdge(i*W+j,H*W+W+i,INT_MAX);
            }else if(vs[i][j]=='T'){
                ty=i,tx=j;
                addEdge(H*W+j,i*W+j,INT_MAX);
                addEdge(H*W+W+i,i*W+j,INT_MAX);
            }else if(vs[i][j]=='o'){
                addEdge(H*W+W+i,H*W+j,1);
                addEdge(H*W+j,H*W+W+i,1);
            }
        }
    if(sy==ty || sx==tx)
        cout<<-1<<endl;
    else{
        int ans=maxFlow(sy*W+sx,ty*W+tx);
        cout<<ans<<endl;
    }
    return 0;
}

