#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

double cache[15+10][1000+10];

class CyclicGame 
{
	public:

		int n;
		vector<int> cells;

		double rec(int pos,int depth)
		{
			double &r=cache[pos][depth];
			if(1000<depth)
				r=0.0;
			else if(r<1000000.0)
				;
			else
			{
				r=0.0;
				for(int i=1;i<=6;i++)
					r+=(cells[(pos+i)%n]+rec((pos+i)%n,depth+1))/6.0;
				r=max(r,0.0);
			}
			return r;
		}

		double estimateBank(vector <int> _cells) 
		{
			cells=_cells;
			n=cells.size();
			for(int i=0;i<15+10;i++)
				for(int j=0;j<1000+10;j++)
					cache[i][j]=1000000.0+10.0;

			return rec(0,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {-10, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.3611111111111112; verify_case(0, Arg1, estimateBank(Arg0)); }
		void test_case_1() { int Arr0[] = {-10, 7, -5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.30434782608695654; verify_case(1, Arg1, estimateBank(Arg0)); }
		void test_case_2() { int Arr0[] = {-1, -2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, estimateBank(Arg0)); }
		void test_case_3() { int Arr0[] = {-40, 9, 9, 9, 9, 9, -44, 9, 9, 9, 9, 9, -40, 15, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.5653612433724144; verify_case(3, Arg1, estimateBank(Arg0)); }
		void test_case_4() { int Arr0[] = {-36, 95, -77, -95, 49, -52, 42, -34, -1, 98, -20, 96, -96, 23, -52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.395613307567126; verify_case(4, Arg1, estimateBank(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	CyclicGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
