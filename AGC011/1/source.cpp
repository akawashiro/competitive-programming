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
    int N;LL C;int K;cin>>N>>C>>K;
    vector<LL> T;
    REP(i,N){
        int a;cin>>a;T.pb(a);}
    sort(ALL(T));
    int r=1,b=T[0],c=0;
    REP(i,N){
        c++;
        if(b+K<T[i] || C<c){
            c=1;
            b=T[i];
            r++;
        }
    }
    cout<<r<<endl;
     return 0;
}
