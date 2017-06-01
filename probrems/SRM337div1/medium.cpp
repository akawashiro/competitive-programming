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
#include <stack>

using namespace std;
typedef long long LL;

class BuildingAdvertise 
{
	public:

		int n;
		vector<int> building;
		vector<int> L,R;

		void makeR(vector<int> h)
		{
			building=vector<int>(n,0);
			int j=0;
			int m=h.size();
			for(int i=0;i<n;i++)
			{
				building[i]=h[j];
				//printf("building[%d]=%d\n",i,building[i]);
				int s=(j+1)%m;
				h[j]=((h[j]^h[s])+13)%835454957;
				j=s;
			}
		}

		LL getMaxArea(vector <int> h, int _n) 
		{
			n=_n;
			makeR(h);

			L=vector<int>(n,0);
			R=vector<int>(n,0);

			stack<int> sta;
			for(int i=0;i<n;i++)
			{
				while(!sta.empty() && building[i]<=building[sta.top()])
					sta.pop();
				if(sta.empty())
					L[i]=0;
				else
					L[i]=sta.top()+1;
				sta.push(i);
			}
			while(!sta.empty())
				sta.pop();
			for(int i=n-1;0<=i;i--)
			{
				while(!sta.empty() && building[i]<=building[sta.top()])
					sta.pop();
				if(sta.empty())
					R[i]=n;
				else
					R[i]=sta.top();
				sta.push(i);
			}
			LL ans=0;
			for(int i=0;i<n;i++)
				ans=max(ans,(LL)(R[i]-L[i])*(LL)building[i]);
			return ans;

		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {3,6,5,6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 15LL; verify_case(0, Arg2, getMaxArea(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {5,0,7,0,2,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; long long Arg2 = 7LL; verify_case(1, Arg2, getMaxArea(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {1048589,2097165}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long long Arg2 = 104858900000LL; verify_case(2, Arg2, getMaxArea(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {1,7,2,5,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 8LL; verify_case(3, Arg2, getMaxArea(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	BuildingAdvertise ___test;
	___test.run_test(-1);
}
// END CUT HERE
