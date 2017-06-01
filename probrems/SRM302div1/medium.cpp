#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

typedef long long LL;
using namespace std;

class IntegerPalindrome 
{
	public:

		LL findByIndex(int K) 
		{
			LL t[30],u[30];
			t[1]=t[2]=9;
			for(int i=3;i<30;i++)
				t[i]=t[i-2]*10;
			u[1]=0;
			for(int i=2;i<30;i++)
				u[i]=u[i-1]+t[i-1];
			int len;
			for(len=1;len<30;len++)
				if(u[len]<=K && K<u[len+1])
					break;
			K-=u[len];

			printf("len=%d K=%d\n",len,K);
			stringstream ss;
			ss << K;
			string s1=ss.str();

			printf("s1=%s\n",s1.c_str());

			if(len%2==0)
			{
				if(s1.size()*2<len)
					s1=string(len/2-s1.size(),'0')+s1;
				s1[0]+=1;
				printf("s1=%s\n",s1.c_str());
				string s2=s1;
				reverse(s1.begin(),s1.end());
				s2+=s1;
				printf("s2=%s\n",s2.c_str());

				stringstream tt(s2);
				LL l;
				tt>>l;
				return l;
			}
			else
			{
				if(s1.size()*2-1<len)
					s1=string(len/2-s1.size()+1,'0')+s1;
				s1[0]+=1;
				printf("s1=%s\n",s1.c_str());
				string s2=s1;
				reverse(s1.begin(),s1.end());
				s2+=s1.substr(1,s1.size()-1);
				printf("s2=%s\n",s2.c_str());
				stringstream tt(s2);
				LL l;
				tt>>l;
				return l;
			}

			return 0;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 8; long long Arg1 = 9LL; verify_case(0, Arg1, findByIndex(Arg0)); }
		void test_case_1() { int Arg0 = 9; long long Arg1 = 11LL; verify_case(1, Arg1, findByIndex(Arg0)); }
		void test_case_2() { int Arg0 = 19; long long Arg1 = 111LL; verify_case(2, Arg1, findByIndex(Arg0)); }
		void test_case_3() { int Arg0 = 235; long long Arg1 = 13731LL; verify_case(3, Arg1, findByIndex(Arg0)); }
		void test_case_4() { int Arg0 = 23746; long long Arg1 = 137484731LL; verify_case(4, Arg1, findByIndex(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	IntegerPalindrome ___test;
	___test.run_test(-1);
}
// END CUT HERE
