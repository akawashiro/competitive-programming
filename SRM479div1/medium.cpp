#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
typedef long long LL;

int n;
LL limit;
LL INF=((LL)1<<LL(50));
LL visited[500];
vector<int> F[500];
vector<int> T[500];
vector<int> P[500];
vector<int> D[500];

class TheAirTripDivOne 
{
	public:

		bool check(LL wait)
		{
			for(int i=0;i<n;i++)
				visited[i]=INF;
			priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > que;
			que.push(make_pair(0,0));

			bool succes=false;
			while(!que.empty())
			{
				LL now=que.top().first;
				int pos=que.top().second;
				que.pop();

				if(visited[pos]<now || limit<now)
					continue;
				else if(pos==n-1)
				{
					succes=true;
					break;
				}
				else
				{
					visited[pos]=now;
					if(pos!=0)
						now+=wait;
					else
						;

					for(int i=0;i<F[pos].size();i++)
						if(F[pos][i]!=INF)
						{
							LL ne=F[pos][i]+((now<F[pos][i])?0:
								(now-F[pos][i]+P[pos][i]-1)/P[pos][i]*P[pos][i])+T[pos][i];
							que.push(make_pair(ne,D[pos][i]));
						}
				}
			}
			return succes;
		}

		int find(int _n, vector <string> flights, int time) 
		{
			limit=time;
			n=_n;

			for(int i=0;i<500;i++)
				F[i].clear(),T[i].clear(),P[i].clear(),D[i].clear();

			string input;
			for(int i=0;i<flights.size();i++)
			{
				for(int j=0;j<flights[i].size();j++)
					if(flights[i][j]==',')
						flights[i][j]=' ';
				input+=flights[i];
			}
			stringstream ss(input);
			int a,b,f,t,p;
			while(ss >> a >> b >> f >> t >> p)
			{
				a--,b--;
				F[a].push_back(f);
				T[a].push_back(t);
				P[a].push_back(p);
				D[a].push_back(b);
			}

			int ceil=time,bottom=1;
			while(5<ceil-bottom)
			{
				int wait=(ceil+bottom)/2;

				if(check(wait))
					bottom=wait;
				else
					ceil=wait;
			}
			for(int i=ceil;bottom<=i;i--)
				if(check(i))
					return i;

			return -1;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 3; string Arr1[] = {"1,2,1,4,7 ", "2,3,9,1,10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 14; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 3; string Arr1[] = {"1,2,1,1,1 2,3,2,1,98"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = -1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 477; string Arr1[] = {"47,74,1,1,1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = -1; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 7; string Arr1[] = {"1,3,15,17,11 1,3,14,16,14 5,7,12,18,18 1,6,13,1", 
			"6,12 1,2,18,14,13 5,6,10,10,18 3,1,10,10,10 1,3",
			",17,16,10 2,3,16,18,16 6,1,15,12,10 2,1,15,18,1",
			"0 4,7,10,16,15 6,3,10,14,10 1,6,19,19,15 1,4,12",
			",10,14 4,7,10,18,14 2,3,16,12,12 1,3,14,10,19 3",
			",7,17,10,12 2,1,14,12,16 4,3,19,11,12 1,6,10,18",
			",12 2,3,16,12,10 6,2,10,18,12 5,1,14,18,12 5,1,",
			"18,10,10 3,2,19,15,10 7,4,16,19,14 6,3,16,12,10",
			" 5,7,14,13,13 1,3,12,10,16 5,7,16,18,15 6,2,18,",
			"12,14 3,2,10,18,16 4,2,18,18,14 1,5,10,18,16 2,",
			"3,10,19,16 1,4,11,18,15 2,1,15,15,14 7,2,10,12,",
			"10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 74; int Arg3 = 33; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg0 = 7; string Arr1[] = {"1,4,10,8,2 4,6,14,8,2 6,2,8,1",
			"0,1 2,7,19,5,1 ",
			"1,5,15,17,11 5,3,10,1",
			"0,18 3,7,12,18,18"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 147; int Arg3 = 35; verify_case(4, Arg3, find(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	TheAirTripDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
