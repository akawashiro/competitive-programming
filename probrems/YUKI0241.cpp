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

#define MAX_V 1000

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

int N,A[50];

int main(void){
    cin>>N;
    REP(i,N)cin>>A[i];
    int src=2*N,dst=2*N+1;
    REP(i,N){
        addEdge(src,i,1);
        addEdge(N+i,dst,1);
        REP(j,N)
            if(j!=A[i])
                addEdge(i,N+j,1);
    }
    int f=maxFlow(src,dst);
    if(f==N){
        REP(i,N)
            REP(j,SZ(G[i]))
                if(G[i][j].cap==0){
                    cout<<G[i][j].to-N<<endl;
                    break;
                }
    }else{
        cout<<-1<<endl;
    }
     return 0;
}
