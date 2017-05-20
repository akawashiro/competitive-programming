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


#define MAX_V 100000

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

int pond[100][100];

int main(void){
    int H,W;
    vector<string> vs;
    memset(pond,-1,sizeof(pond));
    cin>>H>>W;
    REP(i,H){
        string s;cin>>s;vs.pb(s);}
    int nl=2;
    REP(i,H)
        REP(j,W){
            if(vs[i][j]=='S')
                pond[i][j]=0;
            else if(vs[i][j]=='T')
                pond[i][j]=1;
            else if(vs[i][j]=='o'){
                pond[i][j]=nl;
                nl++;
            }
        }
    REP(i,H)
        REP(j,W)
        if(pond[i][j]!=-1){
            int v=pond[i][j];
            REP(k,H){
                int w=pond[k][j];
                if(i==k || w==-1)
                    continue;
                addEdge(v,w,1);
            }
            REP(k,W){
                int w=pond[i][k];
                if(j==k || w==-1)
                    continue;
                addEdge(v,w,1);
            }
        }
    // REP(i,nl){
        // REP(j,SZ(G[i]))
            // printf("i=%d to=%d cap=%d rev=%d\n",i,G[i][j].to,G[i][j].cap,G[i][j].rev);
        // printf("\n");
    // }
    REP(i,SZ(G[0]))
        if(G[0][i].to==1){
            cout<<-1<<endl;
            return 0;
        }
    int ans=maxFlow(0,1);
    cout<<ans<<endl;
    return 0;
}

