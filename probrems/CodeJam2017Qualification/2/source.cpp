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

int checkTidy(string s){
    REP(i,SZ(s)-1)
        if(s[i]>s[i+1])
            return false;
    return true;
}

string solve(string s){
    int n=SZ(s);
    string r;
    for(int i=0;i<n;i++){
        string t=s.substr(0,SZ(s)-i);
        if(0<i && t[SZ(t)-1]=='0')
            continue;
        if(0<i)
            t[SZ(t)-1]--;
        if(checkTidy(t)){
            r=t+string(SZ(s)-SZ(t),'9');
            break;
        }
    }
    return (r[0]=='0')?r.substr(1):r;
}

int main(void){
    int n;
    cin>>n;
    REP(i,n){
        string s,r;
        cin>>s;
        r=solve(s);
        cout<<"Case #"<<i+1<<": "<<r<<endl;
    }
    return 0;
}
