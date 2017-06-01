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

int main(void){
    string s;
    cin>>s;
    LL N=SZ(s),ans=0;
    REP(i,N){
        if(s[i]=='U')
            ans+=(N-1-i) + 2 * i;
        else
            ans+=2 * (N-1-i) + i;
    }
    cout<<ans<<endl;
     return 0;
}
