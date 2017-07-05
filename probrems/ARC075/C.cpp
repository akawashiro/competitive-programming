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

bool dp[100*100+1][100];

int main(void){
    int n;
    vector<int> p;
    cin>>n;
    REP(i,n){
        int a;cin>>a;p.pb(a);
        // cout<<a<<endl;
    }
    dp[0][0]=1;
    REP(j,n){
        REP(i,100*100+1){
            if(dp[i][j]){
                // printf("i=%d j=%d p[j]=%d \n",i,j,p[j]);
                dp[i][j+1]=1;
                dp[i+p[j]][j+1]=1;
            }
        }
    }
    int answer=0;
    REP(i,100*100+1)
        if(dp[i][n] && i%10!=0)
            answer = i;
    cout<<answer<<endl;
    return 0;
}
