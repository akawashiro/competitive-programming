#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

LL DP[1000+20][1000+20];

class PuyoPuyo 
{
	public:
	int theCount(int L, int N) 
	{
		memset(DP,0,sizeof(DP));
		DP[0][0]=1;
		for(int i=0;i<N;i++)
		{
			DP[i+1][L-1]=(DP[i+1][L-1]+4*DP[i][0])%1000000007;
			for(int j=1;j<N;j++)
			{
				DP[i+1][j+L-1]=(DP[i+1][j+L-1]+3*DP[i][j])%1000000007;
				DP[i+1][j-1]=(DP[i+1][j-1]+DP[i][j])%1000000007;
			}
		}

		return DP[N][0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 28; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 58; int Arg2 = 868294620; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 84; int Arg2 = 621871151; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 0; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  PuyoPuyo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
