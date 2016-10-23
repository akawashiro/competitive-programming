#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>

typedef long long LL;
using namespace std;

class MegaCoolNumbers 
{
	public:

		int N,A;
		map<LL,LL> cache;

		LL rec(int pos,int diff,int group,int before)
		{
			LL key=pos;
			key=key*20+diff;
			key=key*2000+group;
			key=key*20+before;

			if(pos==N)
				return (group==A)?1:0;
			else if(cache.find(key)!=cache.end())
				return cache[key];
			else
			{
				LL r=0;
				if(diff<10)
					for(int now=before;now<10;now++)
						if(now-before==diff)
							r=(r+rec(pos+1,diff,group,now))%1000000007;
						else
							r=(r+rec(pos+1,10,group+1,now))%1000000007;
				else
					for(int now=before;now<10;now++)
						r=(r+rec(pos+1,now-before,group,now))%1000000007;
				return cache[key]=r;
			}
		}

		int count(int _N, int _A) 
		{
			N=_N,A=_A;
			LL ans=0;
			cache.clear();
			for(int i=1;i<10;i++)
				ans=(ans+rec(1,10,1,i))%1000000007;;
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 9; verify_case(0, Arg2, count(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 45; verify_case(1, Arg2, count(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7502; verify_case(3, Arg2, count(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	MegaCoolNumbers ___test;
	___test.run_test(-1);
}
// END CUT HERE
