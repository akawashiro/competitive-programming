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

class GogoXMarisaKirisima 
{
	public:
		int solve(vector <string> C) 
		{
			vector<string> G=C;
			int n=C.size(),N=0,M=0;
			for(int i=0;i<n;i++)
				G[i][i]='Y';
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(G[i][k]=='Y'&&G[k][j]=='Y')
							G[i][j]='Y';
			for(int i=0;i<n;i++)
				if(G[0][i]=='Y'&&G[i][n-1]=='Y')
					N++;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(G[0][i]=='Y'&&G[i][n-1]=='Y'&&G[0][j]=='Y'&&G[j][n-1]=='Y'&&C[i][j]=='Y')
						M++;
			if(N==0)
				return 0;
			return M-N+2;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"NYN"
			,"YNY"
				,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
		void test_case_1() { string Arr0[] = {"NNY"
			,"YNY"
				,"YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, solve(Arg0)); }
		void test_case_2() { string Arr0[] = {"NN"
			,"NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
		void test_case_3() { string Arr0[] = {"NYYY"
			,"NNNY"
				,"NNNY"
				,"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	GogoXMarisaKirisima ___test;
	___test.run_test(-1);
}
// END CUT HERE
