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

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()
#define INF 100000

using namespace std;

int t[200],a[200],b[200],c[200],dp[200][200];

int main(void)
{
     int d,n;
     scanf("%d%d",&d,&n);
     FOR(i,0,d)scanf("%d",&t[i]);
     FOR(i,0,n)scanf("%d%d%d",&a[i],&b[i],&c[i]);
     FOR(i,0,200)FOR(j,0,200)dp[i][j]=-INF;
     FOR(i,0,d)FOR(j,0,n){
	  if(i==0){
	       if(a[j]<=t[i]&&t[i]<=b[j])
		    dp[i][j]=0;
	  }else{
	       if(a[j]<=t[i]&&t[i]<=b[j])
		    FOR(k,0,n)
			 dp[i][j]=max(dp[i][j],dp[i-1][k]+abs(c[k]-c[j]));
	  }
     }
     int ans=0;
     FOR(i,0,n)ans=max(ans,dp[d-1][i]);
     printf("%d\n",ans);
     return 0;
}
