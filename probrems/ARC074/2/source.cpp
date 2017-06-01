include <iostream>
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
vector<LL> A;
vector<LL> front;
vector<LL> back;

int main(void){
    cin>>N;
    REP(i,3*N){
        LL a;cin>>a;A.pb(a);
    }
    priority_queue<LL,vector<LL>,greater<LL> > pq1;
    LL sum1=0;
    REP(i,N){
        sum1+=A[i];
        pq1.push(A[i]);
    }
    REP(i,N+1){
        front.pb(sum1);
        sum1+=A[i+N];
        pq1.push(A[i+N]);
        sum1-=pq1.top();
        pq1.pop();
    }
    priority_queue<LL> pq2;
    LL sum2=0;
    FOR(i,2*N,3*N){
        sum2+=A[i];
        pq2.push(A[i]);
    }
    for(int i=2*N-1;N-1<=i;i--){
        back.pb(sum2);
        sum2+=A[i];
        pq2.push(A[i]);
        sum2-=pq2.top();
        pq2.pop();
    }
    reverse(ALL(back));
    LL ans=front[0]-back[0];
    REP(i,N+1){
        // printf("f[%d]=%lld b[%d]=%lld\n",i,front[i],i,back[i]);
        ans=max(ans,front[i]-back[i]);
    }
    cout<<ans<<endl;
     return 0;
}
