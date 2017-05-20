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

int solve(LL H,LL W){
    LL b=H/2;
    LL r=LLMAX;
    for(LL a=max((LL)0,W/3-1);a<=min(W,W/3+2);a++){
        LL rr=max(H*a,max(b*(W-a),(H-b)*(W-a)))-min(H*a,min(b*(W-a),(H-b)*(W-a)));
        r=min(r,rr);
    }
    if(W%3==0)
        r=0;
    else
        r=min(r,H);
    return r;
}

int main(void){
    LL H,W;
    cin>>H>>W;
    LL ans=min(solve(H,W),solve(W,H));
    cout<<ans<<endl;
    return 0;
}
