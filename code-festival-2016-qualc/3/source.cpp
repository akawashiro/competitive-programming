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

int H,W;
char color[1001][1001];
int offset[301];
int sumoffset=0;

void show(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c=color[i+offset[j]][j];
            if(!('a'<=c&&c<='z'))
                c=' ';
            printf("%c",c);
        }
        printf("\n");
    }
    for(int i=0;i<W;i++)
        printf("%d ",offset[i]);
    printf("\n");
}

int solve3(int c){
    // show();
    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;i+j<H;j++){
            if(0<=c-1&&color[i+j][c-1]==color[j][c]){
                ans++;
            }
            if(c+1<W&&color[i+j][c+1]==color[j][c]){
                ans++;
            }
        }
    }
    return ans;
}

int main(void){
    scanf("%d%d",&H,&W);
    REP(i,H)
        scanf("%s",color[i]);
    int ans=0;
    for(int c=1;c<W;c+=2)
        ans+=solve3(c);
    int ans2=0;
    for(int c=0;c<W;c+=2)
        ans2+=solve3(c);
    printf("%d\n",min(ans,ans2));
}

