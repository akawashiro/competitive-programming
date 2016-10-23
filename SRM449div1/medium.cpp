#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;
typedef long long LL;

int offset=8;
int cache[17+5][(1<<17)];

class HexagonalBattlefield 
{
	public:

		int N;
		int field[17+5][17+5];

		void show()
		{
			//debug
			for(int y=0;y<17;y++)
			{
				for(int x=0;x<17;x++)
					printf("%c",field[x][y]);
				printf("\n");
			}
			//debug-end
			return;
		}

		int DFS(int x,int y)
		{
			LL r=0;

			if(x==17)
			{
				int m=0;
				for(int i=0;i<17;i++)
					if(field[i][y+1]=='#')
						m+=(1<<i);
				r=rec(y+1,m);
			}			
			else if(field[x][y]=='#')
				r=DFS(x+1,y);
			else
			{
				if(x<16 && field[x+1][y]=='.')
				{
					field[x][y]=field[x+1][y]='#';
					r=(r+DFS(x+1,y))%2000000011;;
					field[x][y]=field[x+1][y]='.';
				}
				if(y<16 && field[x][y+1]=='.')
				{
					field[x][y]=field[x][y+1]='#';
					r=(r+DFS(x+1,y))%2000000011;;
					field[x][y]=field[x][y+1]='.';
				}
				if(x<16 && y<16 && field[x+1][y+1]=='.')
				{
					field[x][y]=field[x+1][y+1]='#';
					r=(r+DFS(x+1,y))%2000000011;;
					field[x][y]=field[x+1][y+1]='.';
				}
			}
			return (int)r%2000000011;
		}

		int rec(int y,int mask)
		{
			int &r=cache[y][mask];
			if(r!=-1)
				;
			else if(y==17)
				r=1;
			else
				r=DFS(0,y);
			return r;
		}

		int countArrangements(vector <int> X, vector <int> Y, int _N) 
		{
			N=_N;
			for(int x=0;x<17;x++)
				for(int y=0;y<17;y++)
					field[x][y]='#';
			for(int x=-N+1;x<=N-1;x++)
			{
				int b=(x<=0)?-N+1:-N+1+x;
				int c=(x<=0)?N-1+x:N-1;
				for(int y=b;y<=c;y++)
					field[x+offset][y+offset]='.';
			}
			for(int i=0;i<X.size();i++)
				field[X[i]+offset][Y[i]+offset]='#';

			int m=0;
			for(int i=0;i<17;i++)
				if(field[0][i]=='#')
					m+=(1<<i);

			memset(cache,-1,sizeof(cache));
			return rec(0,m);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {-2,0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,0,1,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 10; verify_case(0, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 104; verify_case(2, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arr0[] = {-1,0,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(3, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arr0[] = {0,1,0,0,1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,-1,1,1,0,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(4, Arg3, countArrangements(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	HexagonalBattlefield ___test;
	___test.run_test(-1);
}
// END CUT HERE
