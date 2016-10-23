#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

class ChessMatchup 
{
	public:
	int maximumScore(vector <int> us, vector <int> them) 
	{
		int n=us.size(),ans=0;
		vector<int> usUsed(n,false);
		vector<int> themUsed(n,false);
		sort(us.begin(),us.end());
		sort(them.begin(),them.end());

		for(int i=0;i<n;i++)
			for(int j=n-1;0<=j;j--)
				if(!usUsed[i] && !themUsed[j] && us[i]>them[j])
					themUsed[j]=true,usUsed[i]=true,ans+=2;
		for(int i=0;i<n;i++)
			for(int j=n-1;0<=j;j--)
				if(!usUsed[i] && !themUsed[j] && us[i]==them[j])
					themUsed[j]=true,usUsed[i]=true,ans+=1;

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, maximumScore(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 10, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15, 3, 8, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, maximumScore(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  ChessMatchup ___test;
  ___test.run_test(-1);
}
// END CUT HERE
