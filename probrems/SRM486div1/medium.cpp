#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>

using namespace std;

class QuickSort 
{
	public:

		map<vector<int>,double> cache;

		double rec(vector<int> L)
		{
			double r;
			if(L.size()<2)
				r=0.0;
			else if(cache.find(L)!=cache.end())
				return cache[L];
			else
			{
				r=0.0;
				int n=L.size();
				for(int i=0;i<n;i++)
				{
					vector<int> left,right;
					for(int j=0;j<n;j++)
					{
						if(L[j]<L[i])
						{
							left.push_back(L[j]);
							if(i<j)
								r+=1.0/(double)n;
						}
						if(L[i]<L[j])
						{
							right.push_back(L[j]);
							if(j<i)
								r+=1.0/(double)n;
						}
					}
					r+=(rec(left)+rec(right))/(double)n;
				}
			}
			return cache[L]=r;
		}

		double getEval(vector <int> L) 
		{
			return rec(L);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(0, Arg1, getEval(Arg0)); }
		void test_case_1() { int Arr0[] = {1,2,4,3,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, getEval(Arg0)); }
		void test_case_2() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.6666666666666665; verify_case(2, Arg1, getEval(Arg0)); }
		void test_case_3() { int Arr0[] = {50,40,30,20,10,15,25,35,45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 11.07698412698413; verify_case(3, Arg1, getEval(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	QuickSort ___test;
	___test.run_test(-1);
}
// END CUT HERE
