#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

double DPJ[40+10][40+10][40*40+10];
double DPB[40+10][40+10][40*40+10];

class TheFansAndMeetingsDivOne 
{
	public:
		double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k) 
		{
			int n=minJ.size();
			for(int city=n;0<=city;city--)
				for(int chance=0;chance<=k;chance++)
					for(int left=0;left<=40*40;left++)
					{
						DPJ[city][chance][left]=0.0;
						if(chance==0 && left==0)
							DPJ[city][chance][left]=1.0;
						else if(city==n || chance==0)
							;
						else
						{
							double h=(double)chance/(double)(n-city);
							double a=maxJ[city]-minJ[city]+1.0;
							for(int i=minJ[city];i<=maxJ[city] && 0<=left-i;i++)
								DPJ[city][chance][left]+=h*DPJ[city+1][chance-1][left-i]/a;
							DPJ[city][chance][left]+=(1-h)*DPJ[city+1][chance][left];
						}

						DPB[city][chance][left]=0.0;
						if(chance==0 && left==0)
							DPB[city][chance][left]=1.0;
						else if(city==n || chance==0)
							;
						else
						{
							double h=(double)chance/(double)(n-city);
							double a=maxB[city]-minB[city]+1.0;
							for(int i=minB[city];i<=maxB[city] && 0<=left-i;i++)
								DPB[city][chance][left]+=h*DPB[city+1][chance-1][left-i]/a;
							DPB[city][chance][left]+=(1-h)*DPB[city+1][chance][left];
						}
					}

			double ans=0.0;
			for(int i=0;i<=40*40;i++)
				ans+=DPJ[0][k][i]*DPB[0][k][i];

			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.1111111111111111; verify_case(0, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_1() { int Arr0[] = {5, 2, 5, 1, 1, 2, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 6, 7, 3, 4, 3, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 7, 11, 12, 7, 8, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 10, 9, 33, 14, 7, 11, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; double Arg5 = 4.724111866969009E-5; verify_case(1, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_2() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40, 40, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40, 40, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.0; verify_case(2, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
		void test_case_3() { int Arr0[] = {3, 6, 2, 1, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 9, 5, 6, 5, 10, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 8, 3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 9, 7, 3, 10, 6, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; double Arg5 = 0.047082056525158976; verify_case(3, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	TheFansAndMeetingsDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
