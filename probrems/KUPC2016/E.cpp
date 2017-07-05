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

#define MAX_V 200000+4

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

const int INF = 1e8;

int main(void){
    int H,W;cin>>H>>W;
    vector<string> vs;
    REP(i,H){string s;cin>>s;vs.pb(s);}

    int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int src=2*H*W,dst=2*H*W+1;
    REP(i,H)
        REP(j,W){
            if(i==0||j==0||i==H-1||j==W-1)
                addEdge(i*W+j+H*W,dst,INF);
            if(vs[i][j]=='X'){
                addEdge(src,i*W+j,INF);
                addEdge(i*W+j,i*W+j+H*W,INF);
            }
            else
                addEdge(i*W+j,i*W+j+H*W,1);
            REP(k,4){
                int ii=i+d[k][0],jj=j+d[k][1];
                if(0<=ii&&ii<H&&0<=jj&&jj<W)
                    addEdge(i*W+j+H*W,ii*W+jj,INF);
            }
        }

    int f=maxFlow(src,dst);
    if(INF<=f)
        cout<<-1<<endl;
    else
        cout<<f<<endl;
     return 0;
}
