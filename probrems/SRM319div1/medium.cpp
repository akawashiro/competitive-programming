#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <set>

typedef long long LL;
using namespace std;

class ConstructBST 
{
	public:

		int n;
		LL ans;
		LL C[30][30];
		set<int> se;

		LL rec(int pos)
		{
			if(se.find(pos)==se.end())
				return 0;
			else
			{
				int left=rec(pos*2);
				int right=rec(pos*2+1);
				ans*=C[left][right];

				return left+1+right;
			}
		}

		LL numInputs(vector <int> tree) 
		{
			se.clear();
			n=tree.size();
			ans=1;
			for(int i=0;i<n;i++)
				se.insert(tree[i]);
			for(int i=0;i<30;i++)
				for(int j=0;j<30;j++)
					C[i][j]=(i==0 || j==0)?1:C[i-1][j]+C[i][j-1];
			rec(1);
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, numInputs(Arg0)); }
		void test_case_1() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numInputs(Arg0)); }
		void test_case_2() { int Arr0[] = {1, 2, 5, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(2, Arg1, numInputs(Arg0)); }
		void test_case_3() { int Arr0[] = {1, 2, 4, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(3, Arg1, numInputs(Arg0)); }
		void test_case_4() { int Arr0[] = {2, 4, 3, 62, 7, 15, 1, 31, 5, 14, 28, 57, 56, 114}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 96096LL; verify_case(4, Arg1, numInputs(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	ConstructBST ___test;
	___test.run_test(-1);
}
// END CUT HERE
