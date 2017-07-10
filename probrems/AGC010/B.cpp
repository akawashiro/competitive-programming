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
    LL N,sum=0;
    vector<LL> A;
    vector<LL> D;
    cin>>N;
    REP(i,N){int a;cin>>a;A.pb(a);}
    REP(i,N){
        D.pb(A[(i+1)%N]-A[i]);
        sum+=A[i];
    }
    LL k=sum/(N*(N+1)/2);
    int ok=true;
    if(sum%(N*(N+1)/2)!=0){
        ok=false;
    }
    REP(i,N){
        if(0<D[i]-k||(D[i]-k)%N!=0)ok=false;
    }
    if(ok)cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
     return 0;
}
