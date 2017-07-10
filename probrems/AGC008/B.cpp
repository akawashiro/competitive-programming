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

int N,K;
vector<LL> a;
vector<LL> s;
vector<LL> p;

int main(void){
    cin>>N>>K;
    REP(i,N){
        LL aa;cin>>aa;a.pb(aa);
    }
    REP(i,N){
        if(i==0){
            s.pb(a[i]);
            p.pb(((0<a[i])?a[i]:0));
        }else{
            s.pb(s[i-1]+a[i]);
            p.pb(p[i-1]+((0<a[i])?a[i]:0));
        }
    }
    LL ans=0;
    REP(i,N-K+1){
        LL r=max(0LL,s[i+K-1]-(i==0?0:s[i-1]));
        // printf("s[i+K-1]-(i==0?0:s[i-1])=%lld\n",s[i+K-1]-(i==0?0:s[i-1]));
        r+=(i==0?0:p[i-1]);
        r+=p[N-1]-p[i+K-1];
        ans=max(r,ans);
    }
    cout<<ans<<endl;
    return 0;
}
