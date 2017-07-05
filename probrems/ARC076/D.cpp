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
#define get0(x)     (get<0>(x))
#define get1(x)     (get<1>(x))
#define get2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807LL
#define LLMIN       -9223372036854775808LL
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;
using namespace std;

class UnionFind
{
    vector<int> data;
    vector<int> scale;
    public:
    UnionFind(int n)
    {
        for(int i=0;i<n;i++)
        {
            data.push_back(i);
            scale.push_back(1);
        }
    }
    int root(int n)
    {
        if(data[n]==n)
            return n;
        else
            return data[n]=root(data[n]);
    }
    void set(int x,int y)
    {
        if(root(x)==root(y))
            return;
        scale[root(y)]+=scale[root(x)];
        scale[root(x)]=0;
        data[root(x)]=data[root(y)];
    }
    int size(int n)
    {
        return scale[root(n)];
    }
};


int main(void){
    int N;
    vector<int> x,y;
    vector<pair<int,int> > xp,yp;
    cin>>N;
    REP(i,N){
        int xx,yy;cin>>xx>>yy;
        xp.pb(mp(xx,i));
        yp.pb(mp(yy,i));
    }
    sort(ALL(xp));
    sort(ALL(yp));
    vector<tuple<int,int,int> > vt;
    REP(i,N-1){
        vt.pb(mt(xp[i+1].first-xp[i].first,xp[i+1].second,xp[i].second));
        vt.pb(mt(yp[i+1].first-yp[i].first,yp[i+1].second,yp[i].second));
    }
    sort(ALL(vt));
    int ans=0;
    UnionFind U(N);
    REP(i,SZ(vt)){
        int c=get0(vt[i]),a=get1(vt[i]),b=get2(vt[i]);
        if(U.root(a)!=U.root(b)){
            U.set(a,b);
            ans+=c;
        }
    }
    cout<<ans<<endl;
     return 0;
}
