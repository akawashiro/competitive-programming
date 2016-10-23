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

class Cut 
{
	public:
		int getMaximum(vector <int> eelLengths, int maxCuts) 
		{
			int ans=0;
			vector<int> d10,el;
			for(int i=0;i<(int)eelLengths.size();i++){
				if(eelLengths[i]==10)
					ans++;
				else if(eelLengths[i]%10==0)
					d10.push_back(eelLengths[i]);
				else
					el.push_back(eelLengths[i]);
			}
			sort(d10.begin(),d10.end());
			for(int i=0;i<(int)d10.size();i++){
				int c=d10[i]/10-1;
				if(maxCuts<c){
					ans+=maxCuts;
					maxCuts=0;
				}else{
					ans+=c+1;
					maxCuts-=c;
				}
			}
			for(int i=0;i<(int)el.size();i++){
				int c=el[i]/10;
				if(maxCuts<c){
					ans+=maxCuts;
					maxCuts=0;
				}else{
					ans+=c;
					maxCuts-=c;
				}
			}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {30, 50, 30, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 16; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	Cut ___test;
	___test.run_test(-1);
}
// END CUT HERE
