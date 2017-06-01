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

int n;
map<pair<vector<int>,int>,int> cache;
int rec(vector<int> p,int k)
{
	pair<vector<int>,int> key=make_pair(p,k);
	if(cache.find(key)!=cache.end())
	{
		return cache[key];
	}
	else if(k==0)
	{
		int i;
		for(i=0;i<n;i++)
			if(p[i]!=i)
				break;
		if(i==n)
			return cache[key]=1;
		else
			return cache[key]=0;
	}
	else
	{
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			if(i<p[i] && p[i+1]<=i)
			{
				swap(p[i],p[i+1]);
				ans+=rec(p,k-1);
				swap(p[i],p[i+1]);
			}
		}
		return cache[key]=ans;
	}
}

class AdjacentSwaps 
{
	public:
		int theCount(vector <int> p) 
		{
			n=p.size();
			cache.clear();
			return rec(p,n-1);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
		void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
		void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
		void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
		void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	AdjacentSwaps ___test;
	___test.run_test(-1);
}
// END CUT HERE
