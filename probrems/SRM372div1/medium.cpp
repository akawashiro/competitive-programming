#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

typedef long long LL;
using namespace std;

LL cache[32+10][11+10][500+10];

class RoundOfEleven 
{
	public:

		int n;
		string number;

		LL rec(int pos,int diff,int money)
		{
			LL &r=cache[pos][diff][money];

			if(r!=-1)
				;
			else if(pos==n)
				r=(diff==0)?money:0;
			else
			{
				r=0;
				for(int i=0;i<10;i++)
				{
					int m=i+'0'-number[pos];
					m=(0<m)?m:-m;
					int d=(pos%2==0)?i:(11-i);
					if(0<money-m)
						r+=rec(pos+1,(diff+d)%11,money-m);
				}
			}
			return r;
		}

		long long maxIncome(int input, int money) 
		{
			stringstream ss;
			ss<<input;
			ss>>number;
			n=number.size();

			memset(cache,-1,sizeof(cache));
			return rec(0,0,money);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 31; int Arg1 = 4; long long Arg2 = 6LL; verify_case(0, Arg2, maxIncome(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 31; int Arg1 = 5; long long Arg2 = 11LL; verify_case(1, Arg2, maxIncome(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 110; int Arg1 = 3; long long Arg2 = 7LL; verify_case(2, Arg2, maxIncome(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 19759; int Arg1 = 435; long long Arg2 = 3788217LL; verify_case(3, Arg2, maxIncome(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	RoundOfEleven ___test;
	___test.run_test(-1);
}
// END CUT HERE
