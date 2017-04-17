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
#include <complex>
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

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
      bool operator < (const P& a, const P& b) {
              return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
                }
}
double cross(const P& a, const P& b) {
      return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
      return real(conj(a)*b);
}

struct L : public vector<P> {
      L(const P &a, const P &b) {
              push_back(a); push_back(b);
                }
};

typedef vector<P> G;

struct C {
      P p; double r;
        C(const P &p, double r) : p(p), r(r) { }
};

P projection(const L &l, const P &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}

int main(void){
    int n;
    G p;
    cin>>n;
    REP(i,n){
        double a,b;cin>>a>>b;
        p.pb(P(a,b));
    }
    double ans=DBL_MAX;
    REP(i,n){
        L l(p[(i-1+n)%n],p[(i+1+n)%n]);
        ans=min(ans,distanceLP(l,p[i])/2);
    }
    printf("%.10lf\n",ans);
    return 0;
}
