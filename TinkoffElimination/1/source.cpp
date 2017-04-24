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
int n;
LL k;
vector<LL> p;

int main(void){
    cin>>n>>k;
    REP(i,n){
        LL a;cin>>a;p.pb(a);
    }
    sort(ALL(p));
    LL ans=0;
    FOR(i,1,n){
        if((p[i]-p[0])%k!=0){
            cout<<-1;
            return 0;
        }
        ans+=(p[i]-p[0])/k;
    }
    cout<<ans;
    return 0;
}
