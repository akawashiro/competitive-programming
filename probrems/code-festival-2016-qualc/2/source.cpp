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
int K,T,a[100+1];

int main(void){
    scanf("%d%d",&K,&T);
    REP(i,T)
        scanf("%d",a+i);
    sort(a,a+T);
    REP(i,T-1)
        a[T-1]-=a[i];
    a[T-1]--;
    if(0<a[T-1])
        printf("%d\n",a[T-1]);
    else
        printf("0");
    return 0;
}
