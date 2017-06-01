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
int n,m,q;
vector<int> G[1000000];
int dist[1000000];
double avedist[1000000];

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

int dfs(int pre,int now,int di){
    int r=0;
    REP(i,SZ(G[now]))
        if(G[now][i]!=pre)
            r=max(r,dfs(now,G[now][i],di+1));
    dist[now]=max(di,r);
    return r+1;
}

int main(void){
    cin>>n>>m>>q;
    UnionFind U(n);
    REP(i,m){
        int a,b;cin>>a>>b;a--;b--;
        G[a].pb(b);G[b].pb(a);
        U.set(a,b);
    }
    REP(i,n)
        if(SZ(G[i])==1 && dist[i]==0)
            dfs(-1,i,0);
    map<int,vector<int> > ma;
    REP(i,n){
        avedist[i]=0;
        ma[U.root(i)].pb(i);
    }
    for(map<int,vector<int> >::iterator it=ma.begin();it!=ma.end();it++){
        int sumd=0;
        vector<int> v=(*it).second;
        REP(j,SZ(v))
            sumd+=dist[v[j]];
        REP(j,SZ(v))
            avedist[v[j]]=(double)sumd/(double)SZ(v);
    }
    // REP(i,n)
        // cout<<dist[i]<<" "<<avedist[i]<<endl;
    REP(i,q){
        int a,b;cin>>a>>b;a--;b--;
        if(U.root(a)==U.root(b))printf("-1\n");
        else printf("%.10lf\n",avedist[a]+1.0+avedist[b]);
    }
    return 0;
}
