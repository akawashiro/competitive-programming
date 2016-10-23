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

int main(void)
{
     int n;
     cin>>n;
     map<pair<int,string> ,int> ma;
     FOR(i,0,n){
	  string s;
	  int a;
	  cin>>s>>a;
	  ma[make_pair(SZ(s),s)]+=a;
     }
     FORIT(it,ma)
	  cout<<(*it).first.second<<" "<<(*it).second<<endl;
     return 0;
}
