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

LL N,A,B;
vector<LL> h;

int ok(LL nb){
    LL r=0;
    auto ch = h;
    REP(i,N){
        ch[i]-=B*nb;
        if(0<ch[i])
            r+=(ch[i]+A-B-1)/(A-B);
    }
    return r<=nb;
}

int main(void){
    cin>>N>>A>>B;
    REP(i,N){LL hh;cin>>hh;h.pb(hh);}
    LL u=2e9,b=0;
    while(1<u-b){
        LL m=(u+b)/2;
        if(ok(m))u=m;
        else b=m;
    }
    LL r;
    if(ok(b))
        r=b;
    else
        r=u;
    cout<<r<<endl;
     return 0;
}
