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

using namespace std;
typedef long long LL;

LL MOD=1000000009;

LL cache[100][(1<<12)];

class YetAnotherORProblem 
{
	public:

		int n;
		vector<LL> R;

		LL rec(LL p,int free)
		{
			if(p==-1)
				return 1;
			else
			{
				LL &r=cache[(int)p][free];
				if(r!=-1)
					return r;
				r=0;
				for(int i=0;i<n;i++)
					if(free & (1<<i))
					{
						int f=free;
						for(int j=0;j<n;j++)
							if(((LL)1<<p)&R[j])
								f|=(1<<j);
						r+=rec(p-1,f);
					}
					else
					{
						if(R[i] & ((LL)1<<p))
						{
							int f=free;
							for(int j=0;j<n;j++)
								if(i!=j && (((LL)1<<p)&R[j]))
									f|=(1<<j);
							r+=rec(p-1,f);
						}
					}

				int f=free;
				for(int j=0;j<n;j++)
					if(((LL)1<<p)&R[j])
						f|=(1<<j);
				r+=rec(p-1,f);
				return r%=MOD;
			}
		}

		int countSequences(vector<long long> _R) 
		{
			R=_R;
			n=R.size();

			memset(cache,-1,sizeof(cache));
			return rec(62,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { long Arr0[] = {3,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, countSequences(Arg0)); }
		void test_case_1() { long Arr0[] = {3,3,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, countSequences(Arg0)); }
		void test_case_2() { long Arr0[] = {1,128}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 194; verify_case(2, Arg1, countSequences(Arg0)); }
		void test_case_3() { long Arr0[] = {26,74,25,30}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8409; verify_case(3, Arg1, countSequences(Arg0)); }
		void test_case_4() { long Arr0[] = {1000000000,1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	YetAnotherORProblem ___test;
	___test.run_test(-1);
}
// END CUT HERE
