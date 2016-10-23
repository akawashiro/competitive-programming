#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

#define LIM 3500000
typedef long long LL;
using namespace std;

LL cache[LIM];

class ExtendedHappyNumbers 
{
	public:

		int K;

		LL S(LL n)
		{
			LL r=0;
			while(n!=0)
			{
				LL a=n%10,b=1;
				for(LL i=0;i<K;i++)
					b*=a;
				r+=b;
				n/=10;
			}
			return r;
		}

		LL rec(LL n)
		{
			LL &r=cache[n];
			if(0<r)
				;
			else if(r==-3)
				r=LIM-1;
			else
			{
				r--;
				r=min(n,rec(S(n)));
			}
			return r;
		}

		LL calcTheSum(int A, int B, int _K) 
		{
			K=_K;
			memset(cache,-1,sizeof(cache));
			LL ans=0;
			for(LL i=1;i<LIM;i++)
				rec(i);

			cout << "calc-end" << endl;
			cout << "S(99)=" << S(99) << endl;

			for(LL i=A;i<=B;i++)
				ans+=cache[i];
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 2; long long Arg3 = 14LL; verify_case(1, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 10; int Arg1 = 99; int Arg2 = 1; long long Arg3 = 450LL; verify_case(2, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 535; int Arg1 = 538; int Arg2 = 3; long long Arg3 = 820LL; verify_case(3, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg0 = 100000; int Arg1 = 400000; int Arg2 = 6; long long Arg3 = 5169721292LL; verify_case(4, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	ExtendedHappyNumbers ___test;
	___test.run_test(-1);
}
// END CUT HERE
