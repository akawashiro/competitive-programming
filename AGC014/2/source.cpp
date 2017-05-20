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

class RangeAddRangeSum {
    public:
        int N;
        vector<int> dat, sum_dat;
        RangeAddRangeSum(int n) {
            N = 1;
            while(N < n) N <<= 1;
            dat.assign(2*N-1, 0);
            sum_dat.assign(2*N-1, 0);
        }

        void add(int a, int b, int x) { add(a,b,x,0,0,N); }
        int add(int a, int b, int x, int k, int l, int r) {
            if(b <= l or r <= a) return dat[k];
            if(a <= l and r <= b) {
                sum_dat[k] += x;
                return dat[k] += x*(r-l);
            }
            const int m = (l+r)/2;
            return dat[k] = add(a,b,x,2*k+1,l,m)+add(a,b,x,2*k+2,m,r)+sum_dat[k]*(min(r,b)-max(l,a));
        }

        int sum(int a, int b) { return sum(a,b,0,0,N); }
        int sum(int a, int b, int k, int l, int r) {
            if(b <= l or r <= a) return 0;
            if(a <= l and r <= b) return dat[k];
            const int m = (l+r)/2;
            return sum(a,b,2*k+1,l,m)+sum(a,b,2*k+2,m,r)+sum_dat[k]*(min(r,b)-max(l,a));
        }
};

int main(void){
    int N,M;
    cin>>N>>M;
    RangeAddRangeSum R(N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a>b)
            swap(a,b);
        R.add(a,b,1);
        // cout<<endl;
    }
    REP(i,N-1){
        if(R.sum(i,i+1)%2==1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
