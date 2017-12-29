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
typedef long long LL;
using namespace std;

#define MAX_V 2000000

struct Edge{
        int to,cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
int N;
vector<Edge> G[MAX_V];

void addEdge(int from,int to,int cost){
    G[from].push_back((Edge){to,cost});
}

int d1[MAX_V],d2[MAX_V],pass[MAX_V];
vector<int> vpass;
int dfs1(int v,int p,int d){
    d1[v]=d;
    for(auto e : G[v])
        if(e.to != p)
            dfs1(e.to,v,d+1);
}

int dfs2(int v,int p,int d){
    d2[v]=d;
    for(auto e : G[v])
        if(e.to != p)
            dfs2(e.to,v,d+1);
}

void searchPass(int u,int v){
    pass[v]=1;
    pass[u]=1;
    while(v!=u){
        vpass.PB(v);
        for(auto e : G[v])
            if(d1[v] == d1[e.to] + 1){
                v = e.to;
                break;
            }
        pass[v]=1;
    }
}

int main(void){
    GI(N);
    REP(i,N-1){
        int a,b;
        GI(a);GI(b);
        a--;b--;
        addEdge(a,b,1);
        addEdge(b,a,1);
    }
    int u,v,m=0;
    dfs1(0,-1,0);
    REP(i,N)
        if(m <= d1[i]){
            m = d1[i];
            u = i;
        }
    dfs1(u,-1,0);
    m = 0;
    REP(i,N)
        if(m <= d1[i]){
            m = d1[i];
            v = i;
        }
    dfs2(v,-1,0);
    searchPass(u,v);

    // printf("u=%d v=%d\n",u+1,v+1);
    // for(auto i : vpass)
        // printf("%d on pass\n",i+1);

    LL ans=0;
    REP(i,N)
        if(u!=i && v!=i && !pass[i]){
            ans += (LL)max(d1[i],d2[i]);
        }
    for(auto i : vpass){
        ans += (LL)d1[i];
    }

    cout<<ans<<endl;
    vector<tuple<int,int,int> > bs;
    REP(i,N)
        if(u!=i && v!=i && !pass[i]){
            int b = (d1[i] >= d2[i])?u:v;
            bs.PB(MT(max(d1[i],d2[i]),b,i));
            // printf("%d %d %d\n",b+1,i+1,i+1);
        }
    sort(ALL(bs));
    reverse(ALL(bs));
    for(auto b : bs)
        printf("%d %d %d\n",GET1(b)+1,GET2(b)+1,GET2(b)+1);
    for(auto i : vpass){
        printf("%d %d %d\n",u+1,i+1,i+1);
    }

    return 0;
}

