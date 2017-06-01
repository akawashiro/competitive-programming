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

int N;
LL T[100002],A[100002],lt[100002],ut[100002],la[100002],ua[100002];
LL mod=1000000000+7;

int main(void){
    scanf("%d",&N);
    REP(i,N)scanf("%lld",T+i+1);
    REP(i,N)scanf("%lld",A+i+1);
    for(int i=1;i<=N;i++){
        if(T[i-1]<T[i])
            lt[i]=ut[i]=T[i];
        else{
            ut[i]=T[i];
            lt[i]=1;
        }
    }
    for(int i=N;0<i;i--){
        if(A[i+1]<A[i])
            la[i]=ua[i]=A[i];
        else{
            ua[i]=A[i];
            la[i]=1;
        }
    }
    LL ans=1;
    // for(int i=1;i<=N;i++){
        // printf("ut=%lld ua=%lld lt=%lld la=%lld\n",ut[i],ua[i],lt[i],la[i]);
    // }
    for(int i=1;i<=N;i++){
        LL z=0;
        ans*=max(z,(min(ut[i],ua[i])+1-max(lt[i],la[i])));
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
