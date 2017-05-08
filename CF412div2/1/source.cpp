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
int n,a[1000],b[1000];

int main(void){
    cin>>n;
    REP(i,n){
        cin>>a[i]>>b[i];
        if(a[i]!=b[i]){
            cout<<"rated"<<endl;
            return 0;
        }
    }
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]<a[i+1])
            break;
    if(i==n-1)
        cout<<"maybe"<<endl;
    else
        cout<<"unrated"<<endl;
}
