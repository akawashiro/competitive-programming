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

int main(void){
    int n;
    cin>>n;
    deque<int> de;
    REP(i,n){
        int a;
        cin>>a;
        if(i%2==0)
            de.push_back(a);
        else
            de.push_front(a);
    }
    if((n-1)%2==0)
        reverse(ALL(de));
    REP(i,n)
        cout<<de[i]<<" ";
    cout<<endl;
}
