#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

class KeysInBoxes 
{
	public:

		LL DP[30][30];

		LL gcd(LL a,LL b)
		{
			if(b==0)
				return a;
			else
				return gcd(b,a%b);
		}

		string getAllKeys(int N, int M) 
		{
			DP[1][1]=1;
			for(int i=2;i<=N;i++)
				for(int j=1;j<=M;j++)
					DP[i][j]=DP[i-1][j-1]+(i-1)*DP[i-1][j];

			LL c=0;
			LL m=1;
			for(int i=1;i<=M;i++)
				c+=DP[N][i];
			for(int i=1;i<=N;i++)
				m*=i;
			LL g=gcd(c,m);
			c/=g,m/=g;
			stringstream ss;
			ss << c << "/" << m;

			return ss.str();
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "1/2"; verify_case(0, Arg2, getAllKeys(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "1/1"; verify_case(1, Arg2, getAllKeys(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 3; int Arg1 = 1; string Arg2 = "1/3"; verify_case(2, Arg2, getAllKeys(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "5/6"; verify_case(3, Arg2, getAllKeys(Arg0, Arg1)); }
		void test_case_4() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "17/24"; verify_case(4, Arg2, getAllKeys(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	KeysInBoxes ___test;
	___test.run_test(-1);
}
// END CUT HERE
