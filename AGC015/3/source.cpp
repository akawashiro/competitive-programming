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
int N,M,Q;
int S[2000][2000];

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
int nall(){
    int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    UnionFind U(N*M);
    REP(i,N)REP(j,M)REP(k,4){
        int ii=i+d[k][0],jj=j+d[k][1];
        if(0<=ii && ii<N && 0<=jj && jj<M && S[i][j] && S[ii][jj])
            U.set(ii*M+jj,i*M+j);
    }
    set<int> se;
    REP(i,N)REP(j,M)if(S[i][j]){se.insert(U.root(i*M+j));}
    return SZ(se);
}
int vc[2000][2000],vv[2000][2000],hc[2000][2000],hv[2000][2000],nc[2000];

int main(void){
    scanf("%d%d%d",&N,&M,&Q);
    {
        REP(i,N){
            string s;
            cin>>s;
            REP(j,M)
                S[i][j]=(s[j]=='1')?1:0;
        }
    }
    int ncall = nall();
    REP(i,M-1)REP(j,N){
        int a = (S[j][i] && S[j][i+1]);
        vc[i][j]=(0<j)?vc[i][j-1]+a:a;
        printf("vc[%d][%d] = %d\n",i,j,vc[i][j]);
    }
    REP(i,M)REP(j,N){
        if(j==0)    vv[i][j]=S[j][i];
        else        vv[i][j]=vv[i][j-1]+(!S[j-1][i] && S[j][i]);
    }
    REP(i,N-1)REP(j,M){
        int a = S[i][j] && S[i+1][j];
        hc[i][j] = (0<j)?hc[i][j-1]+a:a;
    }
    REP(i,N)REP(j,M){
        if(j==0)    hv[i][j]=S[i][j];
        else        hv[i][j]=hv[i][j-1]+(!S[i][j-1] && S[i][j]);
    }
    for(int i=M-1;0<=i;i--){
        if(i==M-1)  nc[i]=ncall;
        else        nc[i]=nc[i+1]+vc[i]-vv[i+1];
    }
    REP(i,Q){
        int y1,y2,x1,x2;
        scanf("%d%d%d%d",&y1,&y2,&x1,&x2);
        y1--,y2--,x1--,x2--;
        int n=nc[x2];
        if(x1!=0) n=n+vc[x1-1][N-1]-nc[x1-1];
        int nu=0,nd=0;
        REP(i,y1){
            nu+=hc[i][x2]-((x1==0)?0:hc[i][x1-1]);}
        for(int i=N-1;y2<i;i--)
            nd+=hc[i][x2]-((x1==0)?0:hc[i][x1-1]);
        if(0<y1)
            n=n-nu+hc[y1-1][x2]-((x1==0)?0:hc[y1-1][x1-1]);
        if(y2<N-1)
            n=n-nd+hc[y2][x2]-((x1==0)?0:hc[y2][x1-1]);
        printf("%d\n",n);
    }
     return 0;
}
