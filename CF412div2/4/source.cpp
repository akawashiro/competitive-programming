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
int a[120+1][5];
int solved[5];

double max_score(LL p,LL q){
    if(q<p*2)return 500;
    if(q<p*4)return 1000;
    if(q<p*8)return 1500;
    if(q<p*16)return 2000;
    if(q<p*32)return 2500;
    else      return 3000;
}

double point(LL s,LL w,int t){
    if(t==-1)return 0;
    return max_score(s,w)*(1-(double)t/250.0);
}

int check(LL k){
    double v_score=0,p_score=0;
    REP(i,5){
        LL s=0;
        if(a[0][i]!=-1 && a[1][i]!=-1 && a[1][i]<a[0][i])
            s=k;
        v_score += point(solved[i]+s,n+k,a[0][i]);
        p_score += point(solved[i]+s,n+k,a[1][i]);
    }
    if(v_score > p_score)
        return true;
    else
        return false;
}

int main(void){
    cin>>n;
    REP(i,n)
        REP(j,5){
            cin>>a[i][j];
            if(a[i][j]>=0)
                solved[j]++;
        }
    LL i;
    for(i=0;i<(1<<20);i++)
        if(check(i)){
            cout<<i<<endl;
            return 0;
        }
    cout<<-1<<endl;
    return 0;
}

