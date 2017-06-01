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

int DP[2][1<<20];

class SumOfSelectedCells 
{
	public:
		string hypothesis(vector <string> _table) 
		{
			vector<vector<int> > table;
			for(int i=0;i<(int)_table.size();i++)
			{
				stringstream ss(_table[i]);
				vector<int> v;
				int a;
				while(ss>>a)
					v.push_back(a);
				table.push_back(v);
			}
			int h=table.size();
			int w=table[0].size();
			printf("h=%d w=%d\n",h,w);
			memset(DP,-1,sizeof(DP));
			DP[0][0]=0;
			for(int x=0;x<w;x++)
			{
				memset(DP[(x+1)%2],-1,sizeof(DP[(x+1)%2]));
				for(int used=0;used<(1<<h);used++)
				{
					if(DP[x%2][used]!=-1)
					{
						for(int y=0;y<h;y++)
							if((1<<y) & (~used))
							{
								int u=(used|(1<<y));
								int d=DP[x%2][used]+table[y][x];
								if(DP[(x+1)%2][u]!=-1 && DP[(x+1)%2][u]!=d)
								{
									printf("INCORRECT\n");
									return 0;
								}
								DP[(x+1)%2][u]=d;
							}
					}
				}
			}
			printf("CORRECT\n");
			return 0;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"5 6 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INCORRECT"; verify_case(0, Arg1, hypothesis(Arg0)); }
		void test_case_1() { string Arr0[] = {"11 12 13 14",
			"21 22 23 24",
			"31 32 33 34",
			"41 42 43 44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CORRECT"; verify_case(1, Arg1, hypothesis(Arg0)); }
		void test_case_2() { string Arr0[] = {"3 7",
			"3 7",
			"3 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CORRECT"; verify_case(2, Arg1, hypothesis(Arg0)); }
		void test_case_3() { string Arr0[] = {"1 2 3",
			"4 5 6",
			"9 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INCORRECT"; verify_case(3, Arg1, hypothesis(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	SumOfSelectedCells ___test;
	___test.run_test(-1);
}
// END CUT HERE
