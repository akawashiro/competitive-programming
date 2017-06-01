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
#define LLMAX       9223372036854775807
#define LLMIN       -9223372036854775808
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;

using namespace std;

int N,P,G[100];

int solve(){
    int n[4]={0,0,0,0};
    REP(i,N)
        n[G[i]%P]++;
    if(P==2)
        return n[0]+(n[1]+1)/2;
    else if(P==3){
        int a=min(n[1],n[2]);
        return n[0]+a+(max(n[1],n[2])-a+2)/3;
    }else{
        int a=n[0]+min(n[1],n[3])+n[2]/2;
        int n2=n[2]%2,n1=n[1]-min(n[1],n[3]),n3=n[3]-min(n[1],n[3]);
        if(n2==0){
            if(0<n3)
                a+=(n3+3)/4;
            if(0<n1)
                a+=(n1+3)/4;
        }else{
            int b=max(n1,n3);
            if(b<3)
                a++;
            else
                a+=(1+(n3-2+3)/4);
        }
        return a;
    }
}

int main(void){
    int T;
    cin>>T;
    REP(i,T){
        cin>>N>>P;
        REP(j,N)
            cin>>G[j];
        printf("Case #%d: %d\n",i+1,solve());
    }
    return 0;
}
