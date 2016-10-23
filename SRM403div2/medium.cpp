#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

class TheLargestLuckyNumber 
{
	public:
		int find(int n) 
		{
			int ans=0;
			for(int digit=1;digit<=9;digit++)
				for(int mask=0;mask<(1<<digit);mask++)
				{
					int r=0;
					for(int i=0;i<digit;i++)
						r=r*10+((mask&(1<<i))?7:4);
					if(r<=n)
						ans=max(ans,r);
				}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 100; int Arg1 = 77; verify_case(0, Arg1, find(Arg0)); }
		void test_case_1() { int Arg0 = 75; int Arg1 = 74; verify_case(1, Arg1, find(Arg0)); }
		void test_case_2() { int Arg0 = 5; int Arg1 = 4; verify_case(2, Arg1, find(Arg0)); }
		void test_case_3() { int Arg0 = 474747; int Arg1 = 474747; verify_case(3, Arg1, find(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	TheLargestLuckyNumber ___test;
	___test.run_test(-1);
}
// END CUT HERE
