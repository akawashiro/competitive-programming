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

LL mod=(LL)1000000007;

int main(void){
    int N,M;
    LL ans=0;
    cin>>N>>M;
    if(N>M)swap(N,M);
    if(N==M){
        ans=2;
    }else if(M-N==1){
        ans=1;
    }
    FOR(i,1,N+1){
        ans*=(LL)i;
        ans%=mod;
    }
    FOR(i,1,M+1){
        ans*=(LL)i;
        ans%=mod;
    }
    cout<<ans<<endl;
}
