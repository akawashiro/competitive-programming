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

class DeviceProgramming 
{
	public:

		LL neededBytes(LL maxPacketSize,LL overhead,LL size)
		{
			LL maxInfo=maxPacketSize-overhead;
			LL packetsNeeded=((size%maxInfo==0)?size/maxInfo:size/maxInfo+1);
			return size+packetsNeeded*overhead;
		}

		LL minBytes(vector <int> offset, vector <int> size, int maxPacketSize, int overhead) 
		{
			int n=offset.size();
			LL DP[60];
			vector<int> st,fn;
			for(int i=0;i<n;i++)
			{
				st.push_back(offset[i]);
				fn.push_back(offset[i]+size[i]-1);
			}
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(st[i]>st[j])
					{
						swap(st[i],st[j]);
						swap(fn[i],fn[j]);
					}
			for(int i=0;i<n;i++)
			{
				DP[i]=neededBytes(maxPacketSize,overhead,fn[i]-st[0]+1);
				//printf("DP[%d]=%lld\n",i,DP[i]);
				for(int j=0;j<i;j++)
				{
					DP[i]=min(DP[i],DP[j]+neededBytes(maxPacketSize,overhead,fn[i]-st[j+1]+1));
				}
			}
			return DP[n-1];
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 78LL; verify_case(0, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_1() { int Arr0[] = {0, 42, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 15, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 6; long long Arg4 = 92LL; verify_case(1, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_2() { int Arr0[] = {0, 2, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 5; long long Arg4 = 26LL; verify_case(2, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_3() { int Arr0[] = {10264, 111, 357, 100066, 714}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {117, 134, 235, 2395, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 10; long long Arg4 = 3254LL; verify_case(3, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_4() { int Arr0[] = {1, 100000000, 450000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99999999, 315000000, 500000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 30; long long Arg4 = 943298999LL; verify_case(4, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_5() { int Arr0[] = {0, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 999; long long Arg4 = 2000000000000LL; verify_case(5, Arg4, minBytes(Arg0, Arg1, Arg2, Arg3)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	DeviceProgramming ___test;
	___test.run_test(-1);
}
// END CUT HERE
