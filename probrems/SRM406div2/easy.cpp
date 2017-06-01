#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
int orthogonal[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int diagonal[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};

class HappyCells 
{
	public:
	vector <int> getHappy(vector <string> grid) 
	{
		int h=grid.size(),w=grid[0].size();
		vector<int> ans(3,0);
		for(int y=0;y<h;y++)
			for(int x=0;x<w;x++)
				if(grid[y][x]=='.')
				{
					int ao=0,o=0,ad=0,d=0;
					for(int i=0;i<4;i++)
					{
						int yy=y+orthogonal[i][0],xx=x+orthogonal[i][1];
						if(0<=yy && yy<h && 0<=xx && xx<w)
							ao++,o+=(grid[yy][xx]=='X');
						yy=y+diagonal[i][0],xx=x+diagonal[i][1];
						if(0<=yy && yy<h && 0<=xx && xx<w)
							ad++,d+=(grid[yy][xx]=='X');
					}
					if(ao==o && ad==d)
						ans[0]++;
					else if(ao==o)
						ans[1]++;
					else if(ad==d)
						ans[2]++;
				}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"XXX",
"X.X",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getHappy(Arg0)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getHappy(Arg0)); }
	void test_case_2() { string Arr0[] = {
"XXXXXX",
"X.XXXX",
"XXX.XX",
"X..XXX",
"XXXXXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getHappy(Arg0)); }
	void test_case_3() { string Arr0[] = {"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getHappy(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  HappyCells ___test;
  ___test.run_test(-1);
}
// END CUT HERE
