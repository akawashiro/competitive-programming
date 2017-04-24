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
typedef long long LL;


using namespace std;
int n,k,m,u[2000],v[2000],c[2000];
vector<pair<int,int> > G[82];
int INF=(1<<28);
int cache[82][82][82][82];

int rec(int now,int left,int right,int reftk){
    // printf("now=%d left=%d right=%d reftk=%d\n",now,left,right,reftk);
    int ans;
    if(cache[now+1][left+1][right+1][reftk+1]!=-1){
        return cache[now+1][left+1][right+1][reftk+1];
    }else if(reftk==0){
        ans=0;
    }else{
        ans=INF;
        REP(i,SZ(G[now]))
            if(left<G[now][i].first && G[now][i].first<right){
                if(G[now][i].first < now){
                    ans=min(ans,G[now][i].second+rec(G[now][i].first,G[now][i].first,now,reftk-1));
                    ans=min(ans,G[now][i].second+rec(G[now][i].first,left,G[now][i].first,reftk-1));
                }
                else{
                    ans=min(ans,G[now][i].second+rec(G[now][i].first,now,G[now][i].first,reftk-1));
                    ans=min(ans,G[now][i].second+rec(G[now][i].first,G[now][i].first,right,reftk-1));
                }
            }
    }
    return cache[now+1][left+1][right+1][reftk+1]=ans;
}

int main(void){
    memset(cache,-1,sizeof(cache));
    cin>>n>>k>>m;
    REP(i,m)cin>>u[i]>>v[i]>>c[i];
    REP(i,m){G[u[i]-1].pb(mp(v[i]-1,c[i]));}
    int ans=INF;
    REP(i,n)
        ans=min(ans,rec(i,-1,n,k-1));
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
