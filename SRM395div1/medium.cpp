#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;
LL cache[100+10][100+10][100+10];

class Skyscrapers 
{
	public:

		int N;

		LL rec(int left,int right,int pos)
		{
			if(0<=left && 0<=right)
			{
				LL &r=cache[left][right][pos];

				if(r!=-1)
					return r;
				else if(pos==N)
					r=(left==0 && right==0)?1:0;
				else if(pos==0)
					r=rec(left-1,right-1,pos+1);
				else 
					r=(rec(left-1,right,pos+1)+(pos-1)*rec(left,right,pos+1)+rec(left,right-1,pos+1))%1000000007;

				return r;
			}
			else
				return 0;
		}

		int buildingCount(int _N, int leftSide, int rightSide) 
		{
			N=_N;
			memset(cache,-1,sizeof(cache));
			return rec(leftSide,rightSide,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(0, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 18; verify_case(2, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4872; verify_case(4, Arg3, buildingCount(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	Skyscrapers ___test;
	___test.run_test(-1);
}
// END CUT HERE
