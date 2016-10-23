#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

class RoundAboutCircle 
{
	public:

		int loopSize[200010];
		int nextCell[200010];

		int DFS(int k)
		{
			if(loopSize[k]!=-6)
				return loopSize[k];
			else
				return loopSize[k]=DFS(nextCell[k])+1;
		}

		int maxScore(int N) 
		{
			for(int i=1;i<=N;i++)
			{
				int s=0,t=i;
				while(t!=0)
					s+=t%10,t/=10;
				nextCell[i]=((i+s)%N==0)?N:(i+s)%N;
				//printf("nextCell[%d]=%d\n",i,nextCell[i]);
			}
			for(int i=1;i<=N;i++)
				loopSize[i]=0;
			for(int i=1;i<=N;i++)
				if(loopSize[i]==0)
				{
					int t=i;
					while(loopSize[t]==0)
						loopSize[t]=-2,t=nextCell[t];
					if(loopSize[nextCell[t]]==-2)
					{
						int sz=0;
						while(loopSize[t]==-2)
							loopSize[t]=-4,t=nextCell[t],sz++;
						while(loopSize[t]==-4)
							loopSize[t]=sz,t=nextCell[t];
					}
					t=i;
					while(loopSize[t]==-2)
						loopSize[t]=-6,t=nextCell[t];
				}
			for(int i=1;i<=N;i++)
				if(loopSize[i]==-6)
					DFS(i);
			//for(int i=1;i<=N;i++)
			//	printf("loopSize[%d]=%d\n",i,loopSize[i]);
			//cout << endl;


			return *max_element(loopSize,loopSize+200010-1);
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 11; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { int Arg0 = 566; int Arg1 = 176; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  RoundAboutCircle ___test;
  ___test.run_test(-1);
}
// END CUT HERE
