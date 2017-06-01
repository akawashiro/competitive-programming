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
int N,C,M;
vector<int> P[1000];

int table[1000][1000];

// solution for small
pair<int,int> solve(){
    int nT=0,nP=0;
    // REP(k,C){
    //     REP(l,N){
    //         printf("%d ",table[k][l]);
    //     }
    //     printf("\n");
    // }
    FOR(i,1,N){
        int a=min(table[0][0],table[1][i]);
        table[0][0]-=a;
        table[1][i]-=a;
        nT+=a;
    }
    FOR(i,1,N){
        int a=min(table[0][i],table[1][0]);
        table[0][i]-=a;
        table[1][0]-=a;
        nT+=a;
    }
    REP(i,N)
        REP(j,N){
            if(i==j)
                continue;

            // REP(k,C){
            //     REP(l,N){
            //         printf("%d ",table[k][l]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");

            int a=min(table[0][i],table[1][j]);
            table[0][i]-=a;
            table[1][j]-=a;
            nT+=a;
            // printf("%d\n",a);
            //
            // REP(k,C){
            //     REP(l,N){
            //         printf("%d ",table[k][l]);
            //     }
            //     printf("\n");
            // }
            // printf("\n");
        }
    REP(i,N)
        if(0<table[0][i] || 0<table[1][i]){
            if(i==0){
                nT+=(table[0][i]+table[1][i]);
            }else{
                nT+=max(table[0][i],table[1][i]);
                nP+=min(table[0][i],table[1][i]);
            }
        }
    return mp(nT,nP);
}

int main(void){
    int T;
    cin>>T;
    REP(i,T){
        memset(table,0,sizeof(table));
        cin>>N>>C>>M;
        REP(j,M){
            int p,b;
            cin>>p>>b;
            b--,p--;
            table[b][p]++;
        }
        pair<int,int> ans=solve();
        printf("Case #%d: %d %d\n",i+1,ans.first,ans.second);
    }
    return 0;
}
