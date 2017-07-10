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

int N;
LL A[20000],B[20000],R[20000];

int main(void){
    cin>>N;
    REP(i,N){LL x;cin>>x;x--;R[x]=i+1;}
    REP(i,N){A[i]=(i+1)*30000;B[i]=(N-i)*30000;}
    REP(i,N){B[i]+=R[i];}
    REP(i,N){cout<<A[i]<<" ";}
    cout<<endl;
    REP(i,N){cout<<B[i]<<" ";}
    cout<<endl;
     return 0;
}
