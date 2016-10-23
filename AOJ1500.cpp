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
typedef long long LL;

using namespace std;

int n;
string ID;
int m;
int a[10];
int memo[100000+1][10];

int f(int b){
     return b/10+b%10;
}

int rec(int k,int s){
     if(k==SZ(ID)){
	  return (s%10==0);
     }else if(memo[k][s]!=-1){
	  return memo[k][s];
     }else if(ID[k]!='*'){
	  if(k%2==0)return memo[k][s]=rec(k+1,(s+ID[k]-'0')%10);
	  else return memo[k][s]=rec(k+1,(s+f(2*(ID[k]-'0')))%10);
     }else{
	  int r=0;
	  for(int i=0;i<m;i++){
	       if(k%2==0)r+=rec(k+1,(s+a[i])%10);
	       else r+=rec(k+1,(s+f(2*a[i]))%10);
	  }
	  return memo[k][s]=r;
     }
}

int main(void){
     cin>>n>>ID>>m;
     for(int i=0;i<m;i++)
	  cin>>a[i];
     reverse(ID.begin(),ID.end());
     memset(memo,-1,sizeof(memo));
     int ans=rec(0,0);
     cout<<ans<<endl;
     return 0;
}
