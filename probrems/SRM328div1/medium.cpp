#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int occupied[50];
int cost[50][50];
int INF=(1<<28);

class BlockEnemy 
{
	public:

		int N;

		bool DFS(int here,int from)
		{
			if(occupied[here])
			{
				//printf("here=%d\n",here);
				return true;
			}
			for(int to=0;to<N;to++)
				if(to!=from && cost[here][to]!=INF && DFS(to,here))
					return true;
			return false;
		}

		int minEffort(int _N, vector <string> roads, vector <int> occupiedTowns) 
		{
			N=_N;

			int rN=roads.size();
			vector<int> a(rN),b(rN),e(rN);
			//fill(&cost[0][0],&cost[N-1][N-1],INF);
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					cost[i][j]=INF;
			for(int i=0;i<rN;i++)
			{
				stringstream ss(roads[i]);
				ss >> a[i] >> b[i] >> e[i];
				cost[a[i]][b[i]]=cost[b[i]][a[i]]=e[i];
			}
			for(int i=0;i<rN;i++)
				for(int j=i+1;j<rN;j++)
					if(e[j]<e[i])
						swap(a[i],a[j]),swap(b[i],b[j]),swap(e[i],e[j]);
			
			for(int i=0;i<N;i++)
				occupied[i]=false;
			for(int i=0;i<occupiedTowns.size();i++)
			{
				occupied[occupiedTowns[i]]=true;
				//printf("occupied=%d\n",occupiedTowns[i]);
			}
			//for(int i=0;i<N;i++)
				//if(occupied[i])
					//printf("occupied=%d\n",i);

			int ans=0;
			for(int i=0;i<rN;i++)
			{
				//cout << e[i] << " ";
				//printf("DFS(%d,%d)=%d DFS(%d,%d)=%d\n",a[i],b[i],DFS(a[i],b[i]),b[i],a[i],DFS(b[i],a[i]));
				if(DFS(a[i],b[i]) && DFS(b[i],a[i]))
					ans+=e[i],cost[a[i]][b[i]]=cost[b[i]][a[i]]=INF;
			}
			//cout << endl;

			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minEffort(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, minEffort(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
			"4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(2, Arg3, minEffort(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
			"4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 66; verify_case(3, Arg3, minEffort(Arg0, Arg1, Arg2)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	BlockEnemy ___test;
	___test.run_test(-1);
}
// END CUT HERE
