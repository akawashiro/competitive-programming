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
    string s;
    cin >> s;
    int flag=0;
    for(int i=0;i<SZ(s);i++){
        if(flag==0&&s[i]=='C')
            flag++;
        if(flag==1&&s[i]=='F')
            flag++;
    }
    if(flag==2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
     return 0;
}
