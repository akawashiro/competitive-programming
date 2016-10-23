#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define CLEAR(x) memset(x,0,sizeof x);
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define SZ(c) (int)(c).size()

class AddElectricalWires {
public:
  int n;
  bool a[128][128];
  bool mark[128];
  int curcnt;
  void dfs(int v)
  {
    if (mark[v]) return;
    mark[v]=true;
    curcnt++;
    REP(i,n)
      if (a[v][i])
        dfs(i);
  }
  int maxNewWires(vector <string> wires, vector <int> con) {
    int res=0,curr=0;
    n=SZ(wires);
    REP(i,n) REP(j,n)
      if (a[i][j] = wires[i][j]=='1')
        curr++;
    curr/=2;
    CLEAR(mark);
    int left=n,mxcomp=0;
    REP(i,SZ(con))
    {
      curcnt=0;
      dfs(con[i]);
      res+=curcnt*(curcnt-1)/2;
      left-=curcnt;
      mxcomp=max(mxcomp,curcnt);
    }
    res+=left*(left-1)/2+mxcomp*left;
    return res-curr;
  }
  

};



// Powered by FileEdit
