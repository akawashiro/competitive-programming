#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;
double cache[(1<<15)][20];

class PolygonCover 
{
	public:

		int n;
		vector<double> x;
		vector<double> y;

		double S(int v1,int v2,int v3)
		{
			double e1,e2,e3,s,x1,y1,x2,y2,x3,y3;
			x1=x[v1]-x[v2];
			y1=y[v1]-y[v2];
			x2=x[v2]-x[v3];
			y2=y[v2]-y[v3];
			x3=x[v3]-x[v1];
			y3=y[v3]-y[v1];

			e1=sqrt(x1*x1+y1*y1);
			e2=sqrt(x2*x2+y2*y2);
			e3=sqrt(x3*x3+y3*y3);
			s=(e1+e2+e3)/2;

			return sqrt(s*(s-e1)*(s-e2)*(s-e3));
		}

		double rec(int mask,int k)
		{
			double &r=cache[mask][k];

			if(-1<r)
				return r;
			else if(k==n)
				r=0.0;
			else if(mask & (1<<k))
				r=rec(mask,k+1);
			else
			{
				r=DBL_MAX;
				for(int i=0;i<n;i++)
					for(int j=i+1;j<n;j++)
						if(i!=k && j!=k)
						{
							int m=(mask|(1<<i)|(1<<j)|(1<<k));
							r=min(r,S(i,j,k)+rec(m,k+1));
						}
			}
			return r;
		}

		double getArea(vector<int> _x, vector<int> _y) 
		{
			x.clear();
			y.clear();
			n=_x.size();
			for(int i=0;i<n;i++)
			{
				x.push_back(_x[i]);
				y.push_back(_y[i]);
			}
			for(int i=0;i<(1<<n);i++)
				for(int j=0;j<n;j++)
					cache[i][j]=-2;

			return rec(0,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {0,10,0,-10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,0,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 200.0; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {-1,2,-2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {2,0,-2,-1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,0,-2,-2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.0; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {1,0,-4,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,0,-4,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	PolygonCover ___test;
	___test.run_test(-1);
}
// END CUT HERE
