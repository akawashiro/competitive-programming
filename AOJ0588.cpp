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

char gc(void){
     char c=' ';
     while(c==' '||c=='\n')
	  scanf("%c",&c);
     return c;
}

int main(void)
{
     LL a;
     scanf("%lld",&a);
     while(1){
	  char c=gc();
	  LL b;
	  if(c=='='){
	       printf("%lld\n",a);
	       break;
	  }else if(c=='+'){
	       scanf("%lld",&b);
	       a=a+b;
	  }else if(c=='-'){
	       scanf("%lld",&b);
	       a=a-b;
	  }else if(c=='*'){
	       scanf("%lld",&b);
	       a=a*b;
	  }else{
	       scanf("%lld",&b);
	       a=a/b;
	  }
     }	      
     return 0;
}
