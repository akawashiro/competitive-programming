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

int solve(string s,int k){
    int l=SZ(s),r=0;
    REP(i,l-k+1){
        if(s[i]=='-'){
            r++;
            FOR(j,i,i+k)
                s[j]=(s[j]=='+')?'-':'+';
        }
    }
    REP(i,l)
        if(s[i]=='-')
            return -1;
    return r;
}

int main(void){
    int n;
    cin>>n;
    REP(i,n){
        string s;
        int k;
        cin>>s>>k;
        int r=solve(s,k);
        if(0<=r)
            cout<<"Case #"<<i+1<<": "<<r<<endl;
        else
            cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}

