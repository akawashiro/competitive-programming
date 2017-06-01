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
double cache[(1<<6)+1][6+1][10000+10];

class SchoolTrip 
{
	public:

		int n;
		vector<double> p;

		int popCount(int _mask)
		{
			int r=0;
			for(int i=0;i<28;i++)
				if(_mask & (1<<i))
					r++;
			return r;
		}

		double rec(int left,int turn,int time)
		{
			double &r=cache[left][turn][time];
			if(-1.0<r)
				;
			else if(time==10000 || popCount(left)==1)
				r=0.0;
			else
			{
				r=1.0;
				int ln=popCount(left)-1;
				double minThrow=FLT_MAX;
				for(int hit=turn+1;;hit++)
				{
					hit%=n;
					if(hit==turn)
						break;
					int sleft=left^(1<<hit);
					for(int nTurn=turn+1;;nTurn++)
					{
						nTurn%=n;
						if(sleft&(1<<nTurn))
						{
							minThrow=min(minThrow,p[turn]*rec(sleft,nTurn,time+1));
							break;
						}
					}
				}
				r+=minThrow;
				for(int nTurn=turn+1;;nTurn++)
				{
					nTurn%=n;
					if(left & (1<<nTurn))
					{
						r+=(1.0-p[turn])*rec(left,nTurn,time+1);
						break;
					}
				}
			}
			return r;
		}

		double duration(vector <int> probability) 
		{
			n=probability.size();
			p.clear();
			for(int i=0;i<n;i++)
				p.push_back(probability[i]/100.0);
			for(int i=0;i<(1<<6);i++)
				for(int j=0;j<6;j++)
					for(int k=0;k<10000;k++)
						cache[i][j][k]=-2.0;
			return rec((1<<n)-1,0,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {100,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, duration(Arg0)); }
		void test_case_1() { int Arr0[] = {50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(1, Arg1, duration(Arg0)); }
		void test_case_2() { int Arr0[] = {25,50,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.892383478590375; verify_case(2, Arg1, duration(Arg0)); }
		void test_case_3() { int Arr0[] = {100,100,100,42,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(3, Arg1, duration(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	SchoolTrip ___test;
	___test.run_test(-1);
}
// END CUT HERE
