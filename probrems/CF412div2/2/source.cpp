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
int p,x,y;

int isGoodPoint(int s){
    int i = (s / 50) % 475;
    for(int k=0;k<25;k++){
        i = (i * 96 + 42) % 475;
        if(i+26 == p)
            return true;
    }
    return false;
}

int main(void){
    cin>>p>>x>>y;
    int xx=x%50;
    while(1){
        if(y<=xx){
            if(isGoodPoint(xx)){
                int r=(xx-x+99)/100;
                if(0<r)
                    cout<<r<<endl;
                else
                    cout<<0<<endl;
                return 0;
            }
        }
        xx+=50;
    }
     return 0;
}

