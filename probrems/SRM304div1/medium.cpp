#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

double cache[2500+10][50+10];

class Conditional 
{
	public:

		int v;
		int maxSide;
		double C[55][55];

		double rec(int sum,int nD)
		{
			if(sum<=0)
				return 1.0;
			else if(nD==0)
				return 0.0;
			else
			{
				double &r=cache[sum][nD];
				if(!(r<-1.0))
					return r;
				r=0.0;
				for(int i=1;i<=maxSide;i++)
					if(i!=v)
						r+=rec(sum-i,nD-1)/(double)(maxSide-1);
				return r;
			}
		}

		double probability(int nDice, int _maxSide, int _v, int theSum) 
		{
			v=_v;
			maxSide=_maxSide;
			for(int i=0;i<55;i++)
				for(int j=0;j<55;j++)
					C[i][j]=(i==0 || j==0)?1.0:C[i-1][j]+C[i][j-1];
			double m=0,ans=0;
			fill(&cache[0][0],&cache[2500+10-1][50+10-1],-2.0);
			for(int i=1;i<=nDice;i++)
				m+=C[nDice-i][i]*pow(double(maxSide-1),double(nDice-i));
			for(int i=1;i<=nDice;i++)
			{
				//printf("%2.2f\n",C[nDice-i][i]*pow(maxSide-1,nDice-i));
				//printf("--%2.2f\n",rec(theSum-v*i,nDice-i));
				ans+=C[nDice-i][i]*pow(double(maxSide-1),double(nDice-i))*rec(theSum-v*i,nDice-i);
			}

			//printf("m=%2.2f\n",m);

			return ans/m;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 12; double Arg4 = 0.09090909090909091; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_1() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 6; double Arg4 = 1.0; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_2() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 3; int Arg3 = 3; double Arg4 = 1.0; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	Conditional ___test;
	___test.run_test(-1);
}
// END CUT HERE
