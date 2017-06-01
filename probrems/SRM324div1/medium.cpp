#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <limits.h>

using namespace std;

class TournamentPlan 
{
	public:

		int ABS(int n)
		{
			return (0<n)?n:-n;
		}

		int getTravelDistance(vector <int> street, vector <int> avenue) 
		{
			int ans=INT_MAX,n=street.size();
			for(int s=0;s<n;s++)
				for(int a=0;a<n;a++)
				{
					int r=0;
					for(int i=0;i<n;i++)
						r+=ABS(street[s]-street[i])+ABS(avenue[a]-avenue[i]);
					ans=min(ans,r);
				}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {0,2,0,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, getTravelDistance(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {0,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2000000; verify_case(1, Arg2, getTravelDistance(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {0,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getTravelDistance(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, getTravelDistance(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	TournamentPlan ___test;
	___test.run_test(-1);
}
// END CUT HERE
