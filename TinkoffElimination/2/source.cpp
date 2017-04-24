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
int n,m;
vector<string> ma;
int nhw[1000][1000];
int nvw[1000][1000];

int main(void){
    cin>>n>>m;
    REP(i,n){
        string s;cin>>s;ma.pb(s);
    }
    REP(i,n)
        REP(j,m){
            if(j==0)nhw[i][j]=(ma[i][j]=='*')?1:0;
            else nhw[i][j]=nhw[i][j-1]+((ma[i][j]=='*')?1:0);
        }
    REP(i,m)
        REP(j,n){
            if(j==0)nvw[j][i]=(ma[j][i]=='*')?1:0;
            else nvw[j][i]=nvw[j-1][i]+((ma[j][i]=='*')?1:0);
        }
    pair<int,int> S,T;
    vector<pair<int,int> > ss,ts;
    REP(i,n)
        REP(j,m){
            if(ma[i][j]=='S'){S.first=i;S.second=j;}
            if(ma[i][j]=='T'){T.first=i;T.second=j;}
        }
    // cout<<__LINE__<<endl;
    ss.pb(S);
    for(int i=1;i<n&&S.first+i<n&&ma[S.first+i][S.second]!='*';i++)ss.pb(mp(S.first+i,S.second));
    for(int i=1;i<n&&0<=S.first-i&&ma[S.first-i][S.second]!='*';i++)ss.pb(mp(S.first-i,S.second));
    for(int i=1;i<m&&S.second+i<m&&ma[S.first][S.second+i]!='*';i++)ss.pb(mp(S.first,S.second+i));
    for(int i=1;i<m&&0<=S.second-i&&ma[S.first][S.second-i]!='*';i++)ss.pb(mp(S.first,S.second-i));

    ts.pb(T);
    for(int i=1;i<n&&T.first+i<n&&ma[T.first+i][T.second]!='*';i++)ts.pb(mp(T.first+i,T.second));
    for(int i=1;i<n&&0<=T.first-i&&ma[T.first-i][T.second]!='*';i++)ts.pb(mp(T.first-i,T.second));
    for(int i=1;i<m&&T.second+i<m&&ma[T.first][T.second+i]!='*';i++)ts.pb(mp(T.first,T.second+i));
    for(int i=1;i<m&&0<=T.second-i&&ma[T.first][T.second-i]!='*';i++)ts.pb(mp(T.first,T.second-i));
    FORIT(s, ss){
        FORIT(t, ts){
            int sy=(*s).first,sx=(*s).second;
            int ty=(*t).first,tx=(*t).second;
            // cout<<sy<<" "<<sx<<"-"<<ty<<" "<<tx<<endl;
            if(sy>ty)swap(sy,ty);
            if(sy==ty){
                if(nhw[ty][tx]-nhw[sy][sx]==0){
                    cout<<"YES";
                    return 0;
                }
            }
            if(sx==tx){
                if(nvw[ty][tx]-nvw[sy][sx]==0){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}
