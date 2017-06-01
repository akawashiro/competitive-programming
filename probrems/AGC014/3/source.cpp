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

int H,W,K;
vector<string> room;

int main(void){
    cin>>H>>W>>K;
    REP(i,H){string s;cin>>s;room.pb(s);}
    queue<tuple<int,int,int> > q;
    REP(i,H)
        REP(j,W)
            if(room[i][j]=='S')
                q.push(mt(i,j,K));
    vector<tuple<int,int> > vt;
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(room[get<0>(t)][get<1>(t)]=='%' || room[get<0>(t)][get<1>(t)]=='#')
            continue;
        if(0<get<2>(t)) room[get<0>(t)][get<1>(t)]='%';
        if(0==get<2>(t)) room[get<0>(t)][get<1>(t)]='$';
        if(0<get<2>(t)){
            if(get<0>(t)+1<H) q.push(mt(get<0>(t)+1,get<1>(t),get<2>(t)-1));
            if(get<0>(t)-1>=0) q.push(mt(get<0>(t)-1,get<1>(t),get<2>(t)-1));
            if(get<1>(t)+1<W) q.push(mt(get<0>(t),get<1>(t)+1,get<2>(t)-1));
            if(get<1>(t)-1>=0) q.push(mt(get<0>(t),get<1>(t)-1,get<2>(t)-1));
        }
    }
    int ans=IMAX;
    // REP(i,H)
        // cout<<room[i]<<endl;
    REP(i,H)
        REP(j,W){
            if(room[i][j]=='%' || room[i][j]=='$'){
                int a = min(min(i,j),min(H-i-1,W-j-1));
                a = (a+K-1)/K;
                ans = min(ans,a+1);
            }
            if(room[i][j]=='%' && (i==0 || i==H-1 || j==0 || j==W-1))
                ans=min(ans,1);
        }
    cout<<ans<<endl;
    return 0;
}

