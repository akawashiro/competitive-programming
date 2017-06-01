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
#include <cstring>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()
typedef long long LL;

using namespace std;

int dp[2][2010][3010];

int main(void)
{
     while(1){
	  int N,M,S;
	  scanf("%d%d%d",&N,&M,&S);
	  if(N==0)break;
	  memset(dp,0,sizeof(dp));
	  N*=N;
	  dp[0][0][0]=1;
	  FOR(i,1,N+1){
	       FOR(j,1,M+1)FOR(k,1,S+1)
		    if(0<=k-j)
			 dp[i%2][j][k]=(dp[i%2][j-1][k-1]+dp[(i-1)%2][j-1][k-j])%100000;
	       FOR(j,0,M+1)FOR(k,0,S+1)dp[(i-1)%2][j][k]=0;
	  }
	  int ans=0;
	  FOR(i,0,M+1)ans+=dp[N%2][i][S];
	  printf("%d\n",ans%100000);
     }
     return 0;
}


/*
  int main(void)
  {
  int N,M,S;
  scanf("%d%d%d",&N,&M,&S);
  N*=N;
  dp[0][0][0]=1;
  FOR(i,1,N+1)FOR(j,1,M+1)FOR(k,1,S+1)FOR(l,0,j)
  if(0<=k-j){
  dp[i][j][k]+=dp[i-1][l][k-j];
  dp[i][j][k]%=100000;
  }
  int ans=0;
  FOR(i,0,M+1)ans+=dp[N][i][S];
  printf("%d\n",ans%100000);
  return 0;
  }
*/
