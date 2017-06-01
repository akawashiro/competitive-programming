#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <utility>

using namespace std;

class IntervalSubsets 
{
	public:

		int n;
		int cache[55];
		vector<pair<int,int> > interval;

		int rec(int p)
		{
			int &r=cache[p];
			if(r!=-1)
				return r;
			else
			{
				r=0;
				int ss=interval[p].second+1,se;
				for(int i=0;i<n;i++)
					if(ss<=interval[i].first)
					{
						se=interval[i].second;
						break;
					}
				for(int i=0;i<n;i++)
					if(ss<=interval[i].first && interval[i].first<=se)
					{
						r+=rec(i);
						se=min(se,interval[i].second);
					}
				return (r!=0)?r:r=1;
			}
		}	

		int numberOfSubsets(vector <int> start, vector <int> finish) 
		{
			interval.clear();
			start.push_back(0);
			finish.push_back(0);
			n=start.size();
			for(int i=0;i<n;i++)
				interval.push_back(make_pair(start[i],finish[i]));
			sort(interval.begin(),interval.end());

			memset(cache,-1,sizeof(cache));
			return rec(0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {68,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75,64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {4,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {3,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,4,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {2,3,4,4,4,4,2,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,5,4,5,4,5,3,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
		void test_case_4() { int Arr0[] = {1, 1, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	IntervalSubsets ___test;
	___test.run_test(-1);
}
// END CUT HERE
