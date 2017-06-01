#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int ABS(int n)
{
	return (n<0)?-n:n;
}

class JumpyNum 
{
	public:

		int calc(int input)
		{
			stringstream ss;
			ss<<input;
			string num=ss.str();
			int n=num.size();
			int DP[2][15][10];

			for(int pos=n-1;0<=pos;pos--)
				for(int digit=0;digit<10;digit++)
					for(int match=0;match<2;match++)
						if(pos==n-1)
						{
							if(match)
								DP[match][pos][digit]=(digit<=num[pos]-'0')?1:0;
							else
								DP[match][pos][digit]=1;
						}
						else
						{
							if(match)
							{
								DP[match][pos][digit]=0;
								if(digit<num[pos]-'0')
									for(int nd=0;nd<10;nd++)
									{
										if(2<=ABS(digit-nd))
											DP[match][pos][digit]+=DP[0][pos+1][nd];
									}
								else if(digit==num[pos]-'0')
									for(int nd=0;nd<10;nd++)
									{
										if(2<=ABS(digit-nd))
											DP[match][pos][digit]+=DP[1][pos+1][nd];
									}
								else
									;
							}
							else
							{
								DP[match][pos][digit]=0;
								for(int nd=0;nd<10;nd++)
									if(2<=ABS(digit-nd))
										DP[match][pos][digit]+=DP[0][pos+1][nd];
							}
						}
			int ans=0;
			for(int len=1;len<=n;len++)
			{
				if(len==n)
				{
					for(int first=1;first<num[0]-'0';first++)
						ans+=DP[0][0][first];
					if(0<num[0]-'0')
						ans+=DP[1][0][num[0]-'0'];
				}
				else
				{
					for(int first=1;first<10;first++)
						ans+=DP[0][n-len][first];
				}
			}

			return ans;
		}

		int howMany(int low, int high) 
		{
			//printf("calc(high)=%d\n",calc(high));
			return calc(high)-calc(low-1);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 9; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 9; int Arg1 = 23; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 2000000000; int Arg1 = 2000000000; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 8000; int Arg1 = 20934; int Arg2 = 3766; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	JumpyNum ___test;
	___test.run_test(-1);
}
// END CUT HERE
