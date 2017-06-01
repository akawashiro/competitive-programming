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

pair<LL,LL> solve(LL n, LL k){
    vector<pair<LL,LL> > vp;
    vp.pb(mp(n,1));
    while(1){
        // FORIT(i,vp){
            // printf("l=%lld nl=%lld\n",(*i).first,(*i).second);
        // }
        // printf("\n");

        // printf("SZ(vp)=%d\n",SZ(vp));
        LL l=vp[SZ(vp)-1].first,nl=vp[SZ(vp)-1].second;vp.pop_back();
        // printf("SZ(vp)=%d\n",SZ(vp));

        int i;
        for(i=0;i<SZ(vp);i++)
            if(vp[i].first==l/2){
                vp[i].second+=nl;
                break;
            }
        if(i==SZ(vp))
            vp.pb(mp(l/2,nl));

        for(i=0;i<SZ(vp);i++)
            if(vp[i].first==(l-1)/2){
                vp[i].second+=nl;
                break;
            }
        if(i==SZ(vp))
            vp.pb(mp((l-1)/2,nl));

        LL a=0;
        a=0;
        FORIT(i,vp)a+=(*i).second;
        if(k+1<=a)
            return mp(l/2,(l-1)/2);

        sort(ALL(vp));
    }
    LL a=vp[0].first,b=vp[0].first;
    FORIT(i,vp){
        a=max(a,(*i).first);
        b=min(b,(*i).first);
    }
    return mp(a,b);
}

int main(void){
    int m;
    cin>>m;
    REP(i,m){
        LL n,k;cin>>n>>k;
        auto r=solve(n,k);
        cout<<"Case #"<<i+1<<": "<<r.first<<" "<<r.second<<endl;
    }
    return 0;
}
