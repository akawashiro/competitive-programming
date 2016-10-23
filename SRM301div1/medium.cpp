#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int chain[50+10][50+10];

class EscapingJail 
{
	public:

		int n;

		int getMaxDistance(vector <string> _chain) 
		{
			n=_chain.size();
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					char c=_chain[i][j];
					if('0'<=c && c<='9')
						chain[i][j]=c-'0';
					else if('a'<=c && c<='z')
						chain[i][j]=c-'a'+10;
					else if('A'<=c && c<='Z')
						chain[i][j]=c-'A'+36;
					else
						chain[i][j]=(1<<28);
				}
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						chain[i][j]=min(chain[i][j],chain[i][k]+chain[k][j]);
			int ans=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					ans=max(ans,chain[i][j]);

			return ((1<<28)<=ans)?-1:ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"0568",
			"5094",
			"6903",
			"8430"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, getMaxDistance(Arg0)); }
		void test_case_1() { string Arr0[] = {"0 ",
			" 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getMaxDistance(Arg0)); }
		void test_case_2() { string Arr0[] = {"0AxHH190",
			"A00f3AAA",
			"x00     ",
			"Hf 0  x ",
			"H3  0   ",
			"1A   0  ",
			"9A x  0Z",
			"0A    Z0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 43; verify_case(2, Arg1, getMaxDistance(Arg0)); }
		void test_case_3() { string Arr0[] = {"00",
			"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getMaxDistance(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	EscapingJail ___test;
	___test.run_test(-1);
}
// END CUT HERE
