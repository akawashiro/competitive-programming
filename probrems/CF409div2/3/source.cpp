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
#include <float.h>

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
double p;
vector<double> a,b;

int main(void){
    cin>>n>>p;
    REP(i,n){
        double x,y;cin>>x>>y;a.pb(x);b.pb(y);
    }
    double inf=1e13;
    double ans_ma=inf,ans_mi=0;
    while(ans_ma-ans_mi>1e-6){
        double ans_md=(ans_ma+ans_mi)/2,sum=0;
        REP(i,n)
            sum+=max(0.0,ans_md*a[i]-b[i]);
        if(ans_md*p<sum)
            ans_ma=ans_md;
        else
            ans_mi=ans_md;
    }
    if(ans_ma<inf/2)
        printf("%.10lf\n",ans_ma);
    else
        printf("-1\n");
     return 0;
}
