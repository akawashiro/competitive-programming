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
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

static const LL MOD = 1e9+7;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL a, LL x) {
  LL res = 1;
  while(x > 0) {
  if(x & 1) res = res * a % MOD;
  a = a * a % MOD;
  x >>= 1;
  }
  return res;
}
LL DIV(LL x,LL y){
    return MUL(x,POW(y,MOD-2));
}
LL COMB(LL n, LL r) {
  LL res = 1;
  LL R = min(r,n-r);
  LL RR = R;
  for(LL i = n; i > n - R; i--) {
    res = res * (i % MOD)  % MOD;
    res = res * POW(RR,MOD-2) % MOD;
    RR--;
  }
  return res;
}

const int LEN = 10000+1;
string A,B;
LL DP[LEN+1][2][3][2][8];

int main(void){
    LL nA=0,nB=0;
    cin>>A>>B;
    for(int i=SZ(A)-1;0<=i;i--){
        if('0'<A[i]){
            A[i]--;
            break;
        }else{
            A[i]='9';
        }
    }
    A=string(LEN-SZ(A),'0')+A;
    B=string(LEN-SZ(B),'0')+B;
    memset(DP,0,sizeof(DP));
    DP[0][0][0][0][0]=1;
    REP(i1,LEN)REP(i2,2)REP(i3,3)REP(i4,2)REP(i5,8){
        REP(j,(i2==0?A[i1]-'0'+1:10)){
            LL &a=DP[i1+1][i2 || j<(A[i1]-'0')][(i3+j)%3][i4 || j==3][(i5 * 10 + j) % 8];
            a += DP[i1][i2][i3][i4][i5];
            a %= MOD;
        }
    }
    REP(i2,2)REP(i3,3)REP(i4,2)REP(i5,8)
        if((i3==0 || i4) && i5!=0)
            nA = ADD(nA, DP[LEN][i2][i3][i4][i5]);

    memset(DP,0,sizeof(DP));
    DP[0][0][0][0][0]=1;
    REP(i1,LEN)REP(i2,2)REP(i3,3)REP(i4,2)REP(i5,8){
        REP(j,(i2==0?B[i1]-'0'+1:10)){
            LL &a=DP[i1+1][i2 || j<(B[i1]-'0')][(i3+j)%3][i4 || j==3][(i5 * 10 + j) % 8];
            a += DP[i1][i2][i3][i4][i5];
            a %= MOD;
        }
    }
    REP(i2,2)REP(i3,3)REP(i4,2)REP(i5,8)
        if((i3==0 || i4) && i5!=0)
            nB = ADD(nB, DP[LEN][i2][i3][i4][i5]);
    printf("%lld\n",SUB(nB,nA));
    return 0;
}
