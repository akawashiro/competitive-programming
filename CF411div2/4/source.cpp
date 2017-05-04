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

LL numa[1000000+1];
LL numb[1000000+1];

int main(void){
    string s;
    cin>>s;
    for(int i=SZ(s)-1;0<=i;i--){
        if(i==SZ(s)-1){
            numa[i]=(s[i]=='a')?1:0;
            numb[i]=(s[i]=='b')?1:0;
        }else{
            numa[i]=numa[i+1]+(s[i]=='a')?1:0;
            numb[i]=numb[i+1]+(s[i]=='b')?1:0;
        }
    }
    LL ans=0;
    LL m=0;
    for(int i=SZ(s)-1;0<=i;i--){
        if(s[i]=='b')
            m+=1;
        else{
            ans=(ans+m)%1000000007;
            m*=2;
            m%=1000000007;
        }
    }
    cout<<ans<<endl;
     return 0;
}
