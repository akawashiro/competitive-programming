#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

typedef long long LL;
using namespace std;

LL DP[1000000+10][2];

class NumberPyramids 
{
	public:
		int count(int baseLength, int top) 
		{
			if(20<baseLength)
				return 0;
			int C[21][21];
			for(int i=0;i<21;i++)
				for(int j=0;j<21;j++)
					C[i][j]=(i==0 || j==0)?1:C[i-1][j]+C[i][j-1];
			vector<int> bottom;
			for(int i=0;i<baseLength;i++)
				bottom.push_back(C[baseLength-1-i][i]);
			//for(int i=0;i<baseLength;i++)
			//	cout << bottom[i] << endl;
			for(int i=0;i<baseLength;i++)
				top-=bottom[i];
			if(top<0)
				return 0;

			sort(bottom.begin(),bottom.end());
			reverse(bottom.begin(),bottom.end());

			for(int i=baseLength;0<=i;i--)
				for(int j=0;j<=top;j++)
					if(i==baseLength)
						DP[j][i%2]=(j==0)?1:0;
					else
					{
						DP[j][i%2]=DP[j][(i+1)%2];
						if(0<=j-bottom[i])
							DP[j][i%2]=(DP[j][i%2]+DP[j-bottom[i]][i%2])%1000000009;
					}

			return DP[top][0];
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 5; int Arg1 = 16; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 4; int Arg1 = 15; int Arg2 = 24; verify_case(2, Arg2, count(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 15; int Arg1 = 31556; int Arg2 = 74280915; verify_case(3, Arg2, count(Arg0, Arg1)); }
		void test_case_4() { int Arg0 = 150; int Arg1 = 500; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	NumberPyramids ___test;
	___test.run_test(-1);
}
// END CUT HERE
