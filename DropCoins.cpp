#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cfloat>

using namespace std;

class DropCoins 
{
	public:
	int getMinimum(vector <string> board, int K) 
	{
		int h=board.size();
		int w=board[0].size();
		vector<vector<int> > sum(h,vector<int>(w,0));
		for(int y=0;y<h;y++){
			int a=0;
			for(int x=0;x<w;x++){
				if(board[y][x]=='o')
					a++;
				if(0<y)
					sum[y][x]=sum[y-1][x];
				sum[y][x]+=a;
				//printf("sum[%d][%d]=%d\n",y,x,sum[y][x]);
			}
		}
		int ans=INT_MAX/2;
		for(int y1=0;y1<h;y1++)
			for(int x1=0;x1<w;x1++)
				for(int y2=y1;y2<h;y2++)
					for(int x2=x1;x2<w;x2++){
						int l=sum[y2][x2];
						if(0<y1)
							l-=sum[y1-1][x2];
						if(0<x1)
							l-=sum[y2][x1-1];
						if(0<y1&&0<x1)
							l+=sum[y1-1][x1-1];
						int t=min(y1,(h-1-y2))*2+max(y1,(h-1-y2))
						+min(x1,(w-1-x2))*2+max(x1,(w-1-x2));
						if(l==K){
							//printf("x1=%d x2=%d y1=%d y2=%d\n",x1,x2,y1,y2);
							ans=min(ans,t);
						}
					}
		return (ans!=INT_MAX/2)?ans:-1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o.."
,"oooo"
,"..o."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...."
,".oo."
,".oo."
,"...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  DropCoins ___test;
  ___test.run_test(-1);
}
// END CUT HERE
