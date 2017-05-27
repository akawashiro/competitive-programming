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

int main(void){
    LL N;
    cin>>N;
    vector<LL> ans;
    LL n;
    for(n=0;1LL<<n <= N;n++)
        ;
    N-=1LL<<n;
    REP(i,50)
        ans.pb(i+1);
    REP(i,n+1)
        ans.pb(i+1);
    while(0<N){
        for(int i=n-1;0<=i;i--)
            if(1LL<<i <= N){
    }
    return 0;
}
