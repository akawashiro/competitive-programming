#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()

using namespace std;

int main(void)
{
     int n,m,ans;
     scanf("%d%d",&n,&m);
     ans=m;
     FOR(i,0,n){
	  int a,b;
	  scanf("%d%d",&a,&b);
	  m=m+a-b;
	  if(m<0){
	       printf("0\n");
	       return 0;
	  }
	  ans=max(ans,m);
     }
     printf("%d\n",ans);
     return 0;
}
