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
int n,m;
LL x[100000],y[100000];
LL mod=1000000007;

int main(void){
    cin>>n>>m;
    REP(i,n)cin>>x[i];
    REP(i,m)cin>>y[i];
    LL xl=0;
    REP(i,n-1){
        LL a=n-2;
        LL b=min(i+1,n-1-i);
        a+=b*(b+1)/2%mod;
        cout<<a<<endl;
        xl=(xl+(x[i+1]-x[i])*a)%mod;
    }
    cout<<endl;
    LL yl=0;
    REP(i,m-1){
        LL a=m-2;
        LL b=min(i+1,m-1-i);
        a+=b*(b+1)/2%mod;
        cout<<a<<endl;
        yl=(yl+(y[i+1]-y[i])*a)%mod;
    }
    cout<<xl*yl%mod<<endl;
    return 0;
}
