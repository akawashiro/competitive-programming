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

int watch[1500];

inline int conv(int n){
     return (n/100)*60+n%100;
}

int main(void)
{
     while(1){
	  int n,start,end;
	  scanf("%d%d%d",&n,&start,&end);
	  start=conv(start);end=conv(end);
	  if(n==0)break;
	  memset(watch,0,sizeof(watch));
	  for(int i=start;i<end;i++)
	       watch[i]=n;
	  for(int i=0;i<n;i++){
	       int c;
	       scanf("%d",&c);
	       for(int j=0;j<c;j++){
		    int s,e;
		    scanf("%d%d",&s,&e);
		    s=conv(s);e=conv(e);
		    for(int k=s;k<e;k++)
			 watch[k]--;
	       }
	  }
	  int ans=0,seq=0;
	  for(int i=start;i<=end;i++){
	       if(watch[i]==0){
		    ans=max(ans,seq);
		    seq=0;
	       }else{
		    seq++;
	       }
	  }
	  printf("%d\n",ans);
     }
     return 0;
}

