#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <float.h>

using namespace std;

int n;
double point[(1<<13)];
map<int,double> cache;

int popCount(int _mask)
{
	int r=0;
	for(int i=0;i<28;i++)
		if(_mask & (1<<i))
			r++;
	return r;
}

double rec(int left,int red)
{
	int key=(left<<13)+red;

	if(cache.find(key)!=cache.end())
		return cache[key];
	else if(left==0)
	{
		//printf("%d %f\n",red,point[red]);
		return cache[key]=point[red];
	}
	else
	{
		int turn=n-popCount(left);
		if(turn%2==0)
		{
			double r=-10.0;
			for(int i=0;i<n;i++)
				if(left&(1<<i))
					r=max(r,rec(left^(1<<i),red));
			return cache[key]=r;
		}
		else
		{
			double r=DBL_MAX;
			for(int i=0;i<n;i++)
				if(left&(1<<i))
					r=min(r,rec(left^(1<<i),red^(1<<i)));
			return cache[key]=r;
		}
	}
}

class PointsGame 
{
	public:


		double gameValue(vector <int> pointsX, vector <int> pointsY) 
		{
			n=pointsX.size();
			cache.clear();
			for(int red=0;red<(1<<n);red++)
				if(popCount(red)==(n+1)/2)
				{
					point[red]=0.0;
					for(int i=0;i<n;i++)
						for(int j=i+1;j<n;j++)
							if((0<(red&(1<<i)))^(0<(red&(1<<j))))
							{
								//printf("i=%d j=%d\n",i,j);
								//printf("%d %d\n",(red&(1<<i)),(red&(1<<j)));
								double xd=pointsX[i]-pointsX[j];
								double yd=pointsY[i]-pointsY[j];
								//printf("xd=%f yd=%f\n",xd,yd);
								point[red]+=sqrt(xd*xd+yd*yd);
							}
					//printf("red=%d point=%f\n",red,point[red]);
				}

			return rec((1<<n)-1,(1<<n)-1);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, gameValue(Arg0, Arg1)); }
		void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.198039027185569; verify_case(1, Arg2, gameValue(Arg0, Arg1)); }
		void test_case_2() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.0; verify_case(2, Arg2, gameValue(Arg0, Arg1)); }
		void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, gameValue(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	PointsGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
