#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

class SillySudoku 
{
	public:

		vector<string> group;
		vector<string> board;

		int rec(int pos)
		{
			if(pos==16)
				return 1;
			else
			{
				int y=pos/4,x=pos%4,r=0;
				bool isEmpty=(board[y][x]=='-');

				if(!isEmpty)
				{
					vector<bool> used(5,false);

					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
							if(i==y || j==x || group[i][j]==group[y][x])
							{
								if(i!=y || j!=x)
								{
									char c=board[i][j];
									if(c!='-')
										used[c-'0']=true;
								}
							}
					if(used[board[y][x]-'0'])
						return 0;
					else
						return rec(pos+1);
				}
				else
				{
					vector<bool> used(5,false);

					for(int i=0;i<4;i++)
						for(int j=0;j<4;j++)
							if(i==y || j==x || group[i][j]==group[y][x])
							{
								char c=board[i][j];
								if(c!='-')
									used[c-'0']=true;
							}
					for(int cur=1;cur<5;cur++)
						if(!used[cur])
						{
							board[y][x]=cur+'0';
							r+=rec(pos+1);
						}
					board[y][x]='-';
					return r;
				}
			}
		}

		int countWays(vector <string> _board) 
		{
			board=_board;
			group.push_back("AABB");
			group.push_back("AABB");
			group.push_back("CCDD");
			group.push_back("CCDD");
			return rec(0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"--21", 
			"--34", 
			"2143", 
			"3412"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countWays(Arg0)); }
		void test_case_1() { string Arr0[] = {"--1-", 
			"--1-", 
			"----", 
			"----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countWays(Arg0)); }
		void test_case_2() { string Arr0[] = {"1---", 
			"-42-", 
			"-3--", 
			"----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, countWays(Arg0)); }
		void test_case_3() { string Arr0[] = {"1---", 
			"--1-", 
			"-1--", 
			"---1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, countWays(Arg0)); }
		void test_case_4() { string Arr0[] = {"1---", 
			"----", 
			"----", 
			"----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(4, Arg1, countWays(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	SillySudoku ___test;
	___test.run_test(-1);
}
// END CUT HERE
