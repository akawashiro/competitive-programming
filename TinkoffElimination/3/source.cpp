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
int n;
double cx1,cx2,cy1,cy2;
double rx[100000],ry[100000],vx[100000],vy[100000];
double eps=1e-9;

double cort(int id){
}

int main(void){
    cin>>n;
    cin>>cx1>>cy1>>cx2>>cy2;
    REP(i,n){cin>>rx[i]>>ry[i]>>vx[i]>>vy[i];}
    return 0;
}
