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

int N,M;
LL cache[300+2][300+2][300+2];
vector<tuple<int,int,int> > cond[300+1];

inline bool ok(int R,int G,int B){
    if(R>G) swap(R,G);
    if(G>B) swap(G,B);
    if(R>G) swap(R,G);
    int cs[3]={R,G,B};
    int v=cs[2];
    bool flag=true;
    if(cond[v].size()==0)
            return true;
    for(auto c : cond[v]){
        // printf("c0=%d c1=%d c2=%d\n",get<0>(c),get<1>(c),get<2>(c));
        if(get<2>(c) == 1){
            if(cs[1] < get<0>(c))   ;
            else flag=false;
        }else if(get<2>(c) == 2){
            if(cs[0] < get<0>(c) && get<0>(c) <= cs[1]) ;
            else flag=false;
        }else{
            if(get<0>(c) <= cs[0])  ;
            else flag=false;
        }
    }
    return flag;
}

LL rec(int R,int G,int B){
    int v=max(R,max(G,B));
    LL &r=cache[R+1][G+1][B+1];
    if(v==N-1){
        // printf("R=%d G=%d B=%d\n",R,G,B);
        // printf("v==N\n");
        r=1;
    }else if(r!=-1){
        ;
    }else{
        v++;
        r=0;
        if(ok(v,G,B)) r+=rec(v,G,B);
        if(ok(R,v,B)) r+=rec(R,v,B);
        if(ok(R,G,v)) r+=rec(R,G,v);
        r%=1000000007;
    }
    return r;
}

int main(void){
    memset(cache,-1,sizeof(cache));
    cin>>N>>M;
    REP(i,M){
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        cond[r].pb(mt(l,r,x));
    }
   LL ans = rec(-1,-1,-1);
    cout<<ans<<endl;
    return 0;
}
