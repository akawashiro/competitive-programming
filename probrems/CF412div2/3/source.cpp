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

void solve(){
    LL x,y,p,q;
    cin>>x>>y>>p>>q;
    LL mak=9223372036854775807/q;
    LL mik=0;
    while(1<mak-mik){
        LL mdk=(mak+mik)/2;
        if(mdk*q>=y && mdk*p>=x && mdk*(q-p)>=y-x)
            mak=mdk;
        else
            mik=mdk;
    }
    LL r=(mik*q>=y && mik*p>=x && mik*(q-p)>=y-x)?mik:mak;
    // cout<<"r="<<r<<endl;
    if(9223372036854775807/q<=r)
        cout<<-1<<endl;
    else
        cout<<q*r-y<<endl;
}

int main(void){
    int t;
    cin>>t;
    REP(i,t)
        solve();
    return 0;
}
