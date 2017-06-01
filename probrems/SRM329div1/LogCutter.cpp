#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

class LogCutter 
{
	public:

		int n;
		vector<int> canCut;

		bool check(int L,int C,int mid)
		{
			//printf("check(%d,%d,%d)\n",L,C,mid);

			int beforeCut=0;
			//printf("canCut[0]=%d L=%d C=%d\n",canCut[beforeCut],L,C);
			while(mid<L-canCut[beforeCut] && 0<C)
			{
				if(mid<canCut[beforeCut+1]-canCut[beforeCut])
					return false;
				int nextCut=beforeCut+1;
				while(nextCut+1<n && canCut[nextCut+1]-canCut[beforeCut]<=mid)
					nextCut++;
				C--;
				beforeCut=nextCut;
				//printf("beforeCut=%d\n",beforeCut);
			}

			//printf("canCut[%d]=%d\n",beforeCut,canCut[beforeCut]);
			/*if((L-canCut[beforeCut])<=mid)
				printf("success\n");
			else
				printf("fauld\n");*/
			return (L-canCut[beforeCut]<=mid);
		}

		string bestCut(int L, int A, int K, int C) 
		{
			long long ll=L,aa=A;
			canCut.clear();
			for(long long i=1;i<=K;i++)
				canCut.push_back((aa*i)%(ll-1)+1);
			canCut.push_back(0);
			canCut.push_back(L);
			sort(canCut.begin(),canCut.end());
			canCut.erase(unique(canCut.begin(),canCut.end()),canCut.end());
			n=canCut.size();

			//for(int i=0;i<n;i++)
				//printf("%d ",canCut[i]);
			//printf("\n");

			int ceil=L,bottom=1;
			while(1<ceil-bottom)
			{
				int mid=(ceil+bottom)/2;
				if(check(L,C,mid))
					ceil=mid;
				else
					bottom=mid;
			}

			int opt=(check(L,C,bottom)?bottom:ceil);
			int bc=n-1,fc,fisrtCut;
			while(1)
			{
				fc=bc-1;
				while(canCut[bc]-canCut[fc-1]<=opt && 0<=fc-1)
					fc--;
				if(fc==0)
				{
					if(0<C)
						fisrtCut=1;
					else
						fisrtCut=bc;
					break;
				}
				bc=fc;
				C--;
			}
			stringstream ans;
			ans << opt << " " << canCut[fisrtCut];
			return ans.str();
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; string Arg4 = "5 4"; verify_case(0, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; string Arg4 = "3 3"; verify_case(1, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_2() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; string Arg4 = "2 1"; verify_case(2, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_3() { int Arg0 = 10000; int Arg1 = 999983; int Arg2 = 5000; int Arg3 = 1000; string Arg4 = "13 2"; verify_case(3, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
		void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 100; int Arg3 = 100; string Arg4 = "1 1"; verify_case(4, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	LogCutter ___test;
	___test.run_test(-1);
}
// END CUT HERE
