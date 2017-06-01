#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

class ColorfulDecoration 
{
	public:

		int n;
		int len;
		int dist[110][110];
		int G[110][110];

		int ABS(int n)
		{
			return (n<0)?-n:n;
		}

		bool check()
		{
			memset(G,0,sizeof(G));
			for(int i=0;i<2*n;i++)
				for(int j=0;j<2*n;j++)
					if(i%n!=j%n && dist[i][j]<len)
					{
						int ii=(i<n)?i+n:i-n;
						int jj=(j<n)?j+n:j-n;
						G[i][jj]=1;
					}

			for(int i=0;i<2*n;i++)
				G[i][i]=1;

			for(int k=0;k<2*n;k++)
				for(int i=0;i<2*n;i++)
					for(int j=0;j<2*n;j++)
						if(G[i][k]==1 && G[k][j]==1)
							G[i][j]=1;

			for(int i=0;i<n;i++)
				if(G[i][i+n] && G[i+n][i])
					return false;
			return true;
		}

		int getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb) 
		{
			n=xa.size();
			for(int i=0;i<2*n;i++)
				for(int j=0;j<2*n;j++)
				{
					int x1=(i<n)?xa[i]:xb[i-n];
					int y1=(i<n)?ya[i]:yb[i-n];
					int x2=(j<n)?xa[j]:xb[j-n];
					int y2=(j<n)?ya[j]:yb[j-n];
					dist[i][j]=max(ABS(x1-x2),ABS(y1-y2));

					//printf("dist[%d][%d]=%d\n",i,j,dist[i][j]);
				}
			int ceil=1000000000,bottom=0;
			while(5<ceil-bottom)
			{
				len=(ceil+bottom)/2;
				if(check())
					bottom=len;
				else
					ceil=len;
			}
			for(len=ceil;bottom<=len;len--)
			{
				if(check())
					return len;
			}
			return 0;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = { 10,  0,  7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {  0, 19,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 20, 10, 25 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 20, 35, 25 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 19; verify_case(0, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_1() { int Arr0[] = { 464, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 464, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 464,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 464, 16 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 461; verify_case(1, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_2() { int Arr0[] = { 0, 0, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 1, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1, 1, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_3() { int Arr0[] = { 0, 3, 0, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 6, 0, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 6, 1, 7, 4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 5, 9, 2, 8, 9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(3, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_4() { int Arr0[] = { 1000000000, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 1000000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 1000000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 1000000000 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000000; verify_case(4, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	ColorfulDecoration ___test;
	___test.run_test(-1);
}
// END CUT HERE
