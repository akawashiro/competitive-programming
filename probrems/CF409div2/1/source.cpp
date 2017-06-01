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
int num_VK(string s){
    int ans=0;
    REP(i,SZ(s)-1)
        if(s[i]=='V' && s[i+1]=='K')
            ans++;
    return ans;
}

int main(void){
    string s;
    cin>>s;
    int ans=num_VK(s);
    REP(i,SZ(s)){
        if(s[i]=='V'){
            s[i]='K';
            ans=max(ans,num_VK(s));
            s[i]='V';
        }else{
            s[i]='V';
            ans=max(ans,num_VK(s));
            s[i]='K';
        }
    }
    cout<<ans<<endl;
     return 0;
}
