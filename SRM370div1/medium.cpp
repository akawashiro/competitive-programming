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

class ConnectTheCities 
{
	public:

		int n,dist,range;
		vector<int> pos;
		int cache[105][55];

		int rec(int bP,int k)
		{
			//printf("bP=%d k=%d\n",bP,k);

			int &r=cache[bP][k];
			if(r!=-1)
				;
			else if(k==n)
			{
				if(dist-range<=bP)
					r=0;
				else
					r=1000000;
			}
			else
			{
				r=1000000;
				for(int nP=bP;nP<=min(bP+range,dist);nP++)
					r=min(r,abs(nP-pos[k])+rec(nP,k+1));
			}
			return r;
		}		

		int minimalRange(int distance, int funds, vector <int> position) 
		{
			dist=distance;
			pos=position;
			sort(pos.begin(),pos.end());
			n=pos.size();
			pos.push_back(distance);

			//printf("n=%d\n",n);

			for(range=1;range<=distance;range++)
			{
				memset(cache,-1,sizeof(cache));
				if(rec(0,0)<=funds)
					return range;
			}
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = { 3, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 20; int Arg1 = 100; int Arr2[] = { 0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 63; int Arg1 = 19; int Arr2[] = { 34, 48, 19, 61, 24 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, minimalRange(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	ConnectTheCities ___test;
	//___test.run_test(0);
	___test.run_test(-1);
}
// END CUT HERE
