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

LL N,L,T;
LL W[100000],X[100000],Y[100000],ans[100000];

int main(void){
    scanf("%lld%lld%lld",&N,&L,&T);
    REP(i,N)scanf("%lld%lld",X+i,W+i);
    // printf("%d\n",__LINE__);
    // fflush(stdout);
    REP(i,N){
        if(W[i]==1)Y[i]=(X[i]+T)%L;
        if(W[i]==2)Y[i]=(X[i]-T+L*T)%L;
        // printf("%lld moved to %lld\n",X[i],Y[i]);
    }
    LL a=0,nc=0;
    REP(i,N)if(W[0]!=W[i])a++;
    nc+=(T/L)*a;
    T%=L;
    // printf("%d\n",__LINE__);
    // fflush(stdout);
    if(W[0]==1){
        for(int i=1;i<N;i++)
            if(W[i]==2 && X[i]-X[0]<T*2)
                nc++;
    }else{
        for(int i=N-1;0<i;i--)
            if(W[i]==1 && (X[0]+L-X[i])%L<T*2)
                nc++;
    }
    // printf("%d\n",__LINE__);
    // fflush(stdout);
    int b;
    if(W[0]==1)
        b=nc%N;
    else
        b=((-nc)%N+N)%N;
    vector<pair<LL,int> > vp;
    REP(i,N){
        if(i==0)
            vp.pb(mp(Y[i],b));
        else
            vp.pb(mp(Y[i],-1));
    }
    sort(ALL(vp));
    int s;
    REP(i,N)
        if(vp[i].second!=-1){
            s=i;
            break;
        }
    int t=s-vp[s].second;
    REP(i,N)
        printf("%lld\n",vp[(i+t)%N].first);
     return 0;
}
