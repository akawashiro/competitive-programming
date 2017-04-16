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
typedef long long LL;
using namespace std;

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


int N,M;
vector<int> G[100000];
UnionFind U(100000);

int main(void){
    scanf("%d%d",&N,&M);
    REP(i,M){int a,b;scanf("%d%d",&a,&b);a--;b--;G[a].pb(b);G[b].pb(a);}
    deque<int> path;
    path.pb(0);
    while(1){
        int v=path.back();
        int i;
        for(i=0;i<SZ(G[v]);i++){
            if(U.root(0) != U.root(G[v][i])){
                U.set(0,G[v][i]);
                path.pb(G[v][i]);
                break;
            }
        }
        if(i==SZ(G[v]))
            break;
    }
    while(1){
        int v=path.front();
        int i;
        for(i=0;i<SZ(G[v]);i++){
            if(U.root(0) != U.root(G[v][i])){
                U.set(0,G[v][i]);
                path.push_front(G[v][i]);
                break;
            }
        }
        if(i==SZ(G[v]))
            break;
    }
    printf("%d\n",SZ(path));
    REP(i,SZ(path))
        printf("%d ",path[i]+1);
    return 0;
}
