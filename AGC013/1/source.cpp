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
LL A[100000];

int main(void){
    int N;
    scanf("%d",&N);REP(i,N)scanf("%lld",A+i);
    int ans=1;
    int isFirst=1;
    LL isDecend=0;
    REP(i,N-1){
        LL a=A[i+1]-A[i];
        if(isFirst){
            if(a!=0){
                isFirst=0;
                isDecend=a;
            }
        }else{
            if(0<a){
                if(isDecend*a<0){
                    isFirst=1;
                    ans++;
                }
            }else if(a<0){
                if(isDecend*a<0){
                    isFirst=1;
                    ans++;
                }
            }else{
                ;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
