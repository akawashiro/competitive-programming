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
typedef long long LL;
LL calc(LL n){
	if(n==0||n==1)	return -1;
	LL bag[5];
	LL ans=0;
	LL mod=1000000009;
	memset(bag,0,sizeof(bag));
	bag[0]=n;
	bag[1]++,ans++;
	while(1){
		ans%=mod;
		bag[1]++,ans++;
		bag[4]=0;
		if(bag[0]%bag[1]==0){
			LL t=bag[0]/bag[1];
			ans+=bag[0]*3;
			ans+=t;
			goto GAME_END;
		}else{
			LL t=bag[0]/bag[1]+1;
			ans+=bag[0]*4;
			ans+=t;
		}
	}
GAME_END:
	ans%=mod;
	return ans;
}
class MinskyMystery 
{
	public:
		int computeAnswer(long long N) 
		{
			return calc(N);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { long long Arg0 = 2LL; int Arg1 = 9; verify_case(0, Arg1, computeAnswer(Arg0)); }
		void test_case_1() { long long Arg0 = 3LL; int Arg1 = 27; verify_case(1, Arg1, computeAnswer(Arg0)); }
		void test_case_2() { long long Arg0 = 4LL; int Arg1 = 16; verify_case(2, Arg1, computeAnswer(Arg0)); }
		void test_case_3() { long long Arg0 = 2401LL; int Arg1 = 59058; verify_case(3, Arg1, computeAnswer(Arg0)); }
		void test_case_4() { long long Arg0 = 24LL; int Arg1 = 86; verify_case(4, Arg1, computeAnswer(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	MinskyMystery ___test;
	___test.run_test(-1);
}
// END CUT HERE
