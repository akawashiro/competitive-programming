#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()
typedef long long LL;

using namespace std;

int h,w;
vector<string> town;
string inst;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void solve(){
     int ty,tx,td;
     for(int i=0;i<h;i++)for(int j=0;j<w;j++){
	       if(town[i][j]=='^')ty=i,tx=j,td=0;
	       if(town[i][j]=='v')ty=i,tx=j,td=1;
               if(town[i][j]=='<')ty=i,tx=j,td=2;
	       if(town[i][j]=='>')ty=i,tx=j,td=3;
	  }
     for(int i=0;i<SZ(inst);i++){
	  if(inst[i]=='U'){
	       if(0<ty&&town[ty-1][tx]=='.'){
		    town[ty][tx]='.';town[ty-1][tx]='^';
		    ty--;td=0;
	       }else{
		    town[ty][tx]='^';
		    td=0;
	       }
	  }else if(inst[i]=='D'){
	       if(ty<h-1&&town[ty+1][tx]=='.'){
		    town[ty][tx]='.';town[ty+1][tx]='v';
		    ty++;td=1;
	       }else{
		    town[ty][tx]='v';
		    td=1;
	       }
	  }else if(inst[i]=='L'){
	       if(0<tx&&town[ty][tx-1]=='.'){
		    town[ty][tx]='.';town[ty][tx-1]='<';
		    tx--;td=2;
	       }else{
		    town[ty][tx]='<';
		    td=2;
	       }
	  }else if(inst[i]=='R'){
	       if(tx<w-1&&town[ty][tx+1]=='.'){
		    town[ty][tx]='.';town[ty][tx+1]='>';
		    tx++;td=3;
	       }else{
		    town[ty][tx]='>';
		    td=3;
	       }
	  }else if(inst[i]=='S'){
	       int sy=ty,sx=tx;
	       while(1){
		    sy+=mv[td][0],sx+=mv[td][1];
		    if(sy<0||h<=sy||sx<0||w<=sx)break;
		    if(town[sy][sx]=='*'){town[sy][sx]='.';break;}
		    if(town[sy][sx]=='#')break;
	       }
	  }
     }
     
}

int main(void){
     int testcase;
     cin>>testcase;
     for(;0<testcase;testcase--){
	  town.clear();
	  cin>>h>>w;
	  for(int i=0;i<h;i++){
	       string s;
	       cin>>s;
	       town.push_back(s);
	  }
	  int a;
	  cin>>a;
	  cin>>inst;
	  solve();
	  for(int i=0;i<h;i++){
	       cout<<town[i];
	       if(!(testcase==1&&i==h-1))
		    cout<<endl;
	  }
	  if(testcase!=0)
	       cout<<endl;
     }
     return 0;
}
