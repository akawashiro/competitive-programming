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

using namespace std;
typedef long long LL;

static const LL MOD=1000000007;
LL ADD(LL x,LL y){	return (x+y)%MOD;	}
LL SUB(LL x,LL y){	return (x-y+MOD)%MOD;	}
LL MUL(LL x,LL y){	return ((x*y)%MOD+MOD)%MOD;	}
LL POW(LL x,LL e)
{
	LL r=1;
	for(;e;x=MUL(x,x),e>>=1)
		if(e&1)
			r=MUL(r,x);
	return r;
}
LL DIV(LL x,LL y){	return MUL(x,POW(y,MOD-2));	}
LL COMB(LL n,LL k)
{
	LL r=1;
	for(LL i=1;i<=k;i++)
		r=DIV(MUL(r,n-i+1),i);
	return r;
}

class SumOfPowers 
{
	public:

		LL n,k;
		LL bin[60][60];
		LL cache[60];

		LL rec(int p)
		{
			LL &r=cache[p];
			if(r!=-1)
				;
			else if(p==0)
				r=n;
			else if(p==1)
				r=n*(n+1)/2%MOD;
			else
			{
				r=(POW(n+1,p+1)-1)%MOD;
				for(int i=0;i<p;i++)
				{
					r-=MUL(bin[p+1][i],rec(i));
					r=(r%MOD+MOD)%MOD;
				}
				r=DIV(r,bin[p+1][p]);
			}
			return r;
		}

		int value(int _n, int _k) 
		{
			n=_n,k=_k;
			for(int i=0;i<60;i++)
				for(int j=0;j<60;j++)
					if(i<j)
						bin[i][j]=0;
					else if(j==0)
						bin[i][j]=1;
					else
						bin[i][j]=(bin[i-1][j]+bin[i-1][j-1])%MOD;
			/*for(int i=1;i<10;i++)
				for(int j=1;j<=i;j++)
					printf("bin[%d][%d]=%lld\n",i,j,bin[i][j]);*/
			memset(cache,-1,sizeof(cache));
			return rec(k);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 15; verify_case(0, Arg2, value(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 30; verify_case(1, Arg2, value(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 13; int Arg1 = 5; int Arg2 = 1002001; verify_case(2, Arg2, value(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 123456789; int Arg1 = 1; int Arg2 = 383478132; verify_case(3, Arg2, value(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	SumOfPowers ___test;
	___test.run_test(-1);
}
// END CUT HERE
