#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
typedef long long LL;

int n;
LL k;
int range[55][55][2][2];
LL cache[55][55][2];

class ContiguousCache 
{
	public:

		LL intersect(int a1,int a2,int b1,int b2)
		{
			if(a1<=b1 && b1<=a2 && a2<=b2)
				return a2-b1+1;
			else if(a1<=b1 && b2<=a2)
				return b2-b1+1;
			else if(b1<=a1 && a2<=b2)
				return a2-a1+1;
			else if(b1<=a1 && a1<=b2 && b2<=a2)
				return b2-a1+1;
			else
				return 0;
		}

		LL rec(int a1,int a2,int slide)
		{
			//printf("rec(%d,%d,%d)\n",a1,a2,slide);

			int b1=a2+1,b2,nextSlide;
			LL &r=cache[a1][a2][slide];

			if(r!=-1)
				;
			else if(b1==n)
				r=0;
			else	
			{
				r=LLONG_MAX;
				for(b2=b1;b2<n && range[b1][b2][0][0]!=-1;b2++)
					for(nextSlide=0;nextSlide<2;nextSlide++)
					{
						r=min(r,k-intersect(range[a1][a2][slide][0],range[a1][a2][slide][1],range[b1][b2][nextSlide][0],range[b1][b2][nextSlide][1])+rec(b1,b2,nextSlide));
						//printf("b1=%d b2=%d\n",b1,b2);
						//r=min(r,k+rec(b1,b2,nextSlide));
					}
			}

			return r;
		}

		LL minimumReads(int _n,int _k,vector<int> addresses) 
		{
			reverse(addresses.begin(),addresses.end());
			addresses.push_back(INT_MIN/2);
			reverse(addresses.begin(),addresses.end());

			n=addresses.size(),k=_k;
			//printf("n=%d k=%lld\n",n,k);
			//printf("k=%lld\n",k);
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					LL mi=INT_MAX/2,ma=INT_MIN/2;
					for(int l=min(i,j);l<=max(i,j);l++)
					{
						mi=min(mi,(LL)addresses[l]);
						ma=max(ma,(LL)addresses[l]);
					}
					range[i][j][0][0]=-1,range[i][j][0][1]=-1;
					range[i][j][1][0]=-1,range[i][j][1][1]=-1;
					if(ma-mi<k)
					{
						range[i][j][0][0]=mi,range[i][j][0][1]=mi+k-1;
						//printf("range[%d::%d]=[%d::%d]\n",addresses[i],addresses[j],range[i][j][0][0],range[i][j][0][1]);
						range[i][j][1][0]=ma-k+1,range[i][j][1][1]=ma;
						//printf("range[%d::%d]=[%d::%d]\n",addresses[i],addresses[j],range[i][j][1][0],range[i][j][1][1]);
					}
				}

			memset(cache,-1,sizeof(cache));
			return rec(0,0,0);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 100; int Arg1 = 3; int Arr2[] = {0, 2, 16, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 7LL; verify_case(0, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 100; int Arg1 = 10; int Arr2[] = {1,10,19,28,30,37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 29LL; verify_case(1, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 1000000000; int Arg1 = 500000000; int Arr2[] = {0, 999999999, 1, 500000000, 500000001, 987654321}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1987654320LL; verify_case(2, Arg3, minimumReads(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 8; int Arg1 = 2; int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(3, Arg3, minimumReads(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	ContiguousCache ___test;
	___test.run_test(-1);
}
// END CUT HERE
