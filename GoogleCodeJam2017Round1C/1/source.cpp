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
int K,N;
vector<pair<double, double> > RH;
double cache[1000+1][1000+1];

double rec(int v,int k){
    double r;
    if(k==0||v==N){
        r=0;
    }else if(-0.5<cache[v][k]){
        r=cache[v][k];
    }else{
        if(k==K){
            r=max(rec(v+1,k),RH[v].first*RH[v].first*M_PI+RH[v].first*2*RH[v].second*M_PI+rec(v+1,k-1));
        }else{
            r=max(rec(v+1,k),RH[v].first*2*RH[v].second*M_PI+rec(v+1,k-1));
        }
    }
    return cache[v][k]=r;
}

int main(void){
    int T;
    scanf("%d",&T);
    REP(i,T){
        RH.clear();
        scanf("%d%d",&N,&K);
        REP(j,N){
            double r,h;
            scanf("%lf%lf",&r,&h);
            RH.pb(mp(r,h));
        }
        sort(ALL(RH));
        reverse(ALL(RH));
        REP(j,1001)REP(l,1001)cache[j][l]=-1;
        printf("Case #%d: %.10lf\n",i+1,rec(0,K));
    }
     return 0;
}

