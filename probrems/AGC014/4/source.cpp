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

int N;
vector<int> G[100000];
int used[100000];

void dfs(int p,int v){
    if(SZ(G[v])==1 && p!=-1){
        if(!used[p] && !used[v]){
            used[v]=1;
            used[p]=1;
        }
    }else{
        REP(i,SZ(G[v]))
            if(G[v][i]!=p)
                dfs(v,G[v][i]);
        REP(i,SZ(G[v]))
            if(G[v][i]!=p && !used[G[v][i]] && !used[v]){
                used[G[v][i]]=1;
                used[v]=1;
                break;
            }
    }
}

int main(void){
    cin>>N;
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(-1,0);
    REP(i,N)
        if(!used[i]){
            // printf("i=%d\n",i);
            cout<<"First"<<endl;
            return 0;
        }
   cout<<"Second"<<endl;
     return 0;
}
