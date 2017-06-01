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
int cc[51][26];

int main(void){
    cin>>n;
    REP(i,n){
        string s;cin>>s;
        REP(j,SZ(s))
            cc[i][s[j]-'a']++;
    }
    REP(j,26)cc[n][j]=INT_MAX;
    REP(i,n)REP(j,26)cc[n][j]=min(cc[n][j],cc[i][j]);
    string r;
    REP(j,26)r+=string(cc[n][j],'a'+j);
    cout<<r<<endl;
    return 0;
}
