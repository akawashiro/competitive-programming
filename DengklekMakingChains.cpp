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

class DengklekMakingChains 
{
	public:
		int maxBeauty(vector <string> C) 
		{
			int ans=0,n=C.size();
			for(int i=0;i<n;i++)
				if(C[i][0]!='.'&&C[i][1]!='.'&&C[i][2]!='.')
					ans+=C[i][0]-'0'+C[i][1]-'0'+C[i][2]-'0';
			int a=0;
			for(int i=0;i<n;i++)
				if(C[i][2]!='.'&&(C[i][0]=='.'||C[i][1]=='.')){
					int b=0,c=0;
					b+=(C[i][1]=='.')?0:C[i][1]-'0';
					b+=(C[i][2]=='.')?0:C[i][2]-'0';
					for(int j=0;j<n;j++){
						if(i!=j&&C[j][0]!='.'&&(C[j][1]=='.'||C[j][2]=='.')){
							int cc=0;
							cc+=(C[j][0]=='.')?0:C[j][0]-'0';
							cc+=(C[j][1]=='.')?0:C[j][1]-'0';
							c=max(cc,c);
						}
					}
					a=max(a,b+c);
				}
			for(int i=0;i<n;i++)
				if(C[i][0]!='.'&&(C[i][1]=='.'||C[i][2]=='.')){
					int b=0,c=0;
					b+=(C[i][0]=='.')?0:C[i][0]-'0';
					b+=(C[i][1]=='.')?0:C[i][1]-'0';
					for(int j=0;j<n;j++){
						if(i!=j&&C[j][2]!='.'&&(C[j][0]=='.'||C[j][1]=='.')){
							int cc=0;
							cc+=(C[j][1]=='.')?0:C[j][1]-'0';
							cc+=(C[j][2]=='.')?0:C[j][2]-'0';
							c=max(cc,c);
						}
					}
					a=max(a,b+c);
				}
			ans=ans+a;
			for(int i=0;i<n;i++){
				int c=0,j=0;
				while(j<3){
					int d=0;
					while(C[i][j]!='.'&&j<3)
						d+=C[i][j]-'0',j++;
					c=max(c,d);
					j++;
				}
				ans=max(ans,c);
			}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
		void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
		void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
		void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
		void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
		void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	DengklekMakingChains ___test;
	___test.run_test(-1);
}
// END CUT HERE
