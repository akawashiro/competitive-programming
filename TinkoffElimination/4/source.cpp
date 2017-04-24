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
int n,k,m,u[2000],v[2000];
LL c[2000];
vector<pair<int,LL> > G[80];
LL INF=(1<<30);

LL rec(int pre,int now,int rk){
    LL ans;
    if(rk==0){
        ans=0;
    }else{
        ans=INF;
        REP(i,SZ(G[now])){
            int nex=G[now][i].first;
            if(pre<now&&(
        }
    }
}

int main(void){
    cin>>n>>k>>m;
    REP(i,m)cin>>u[i]>>v[i]>>c[i];
    REP(i,m){G[u[i]-1].pb(mp(v[i]-1,c[i]));}
    return 0;
}
