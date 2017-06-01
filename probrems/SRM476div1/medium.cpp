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
int K,gN;
int E[40];
int G[16][16];
double C[40][40];
double cache[16][1<<16];

void init()
{
	for(int i=0;i<40;i++)
		for(int j=0;j<40;j++)
			if(i<j)
				C[i][j]=0;
			else if(j==0)
				C[i][j]=1;
			else
				C[i][j]=C[i-1][j]+C[i-1][j-1];
	for(int i=0;i<16;i++)
		for(int j=0;j<1<<16;j++)
			cache[i][j]=-2.0;
}

void makeG(vector<string> input)
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			G[i][j]=0;
	gN=1;
	set<int> masaoFriends;
	for(int i=0;i<input.size();i++)
	{
		int a;
		stringstream ss(input[i]);
		vector<int> v;
		while(ss>>a)
			v.push_back(a);
		if(i==0)
		{
			masaoFriends.insert(1);
			for(int j=0;j<v.size();j++)
				masaoFriends.insert(v[j]);
			for(int j=0;j<v.size();j++)
			{
				int p=distance(masaoFriends.begin(),masaoFriends.find(i+1));
				int q=distance(masaoFriends.begin(),masaoFriends.find(v[j]));
				G[p][q]=G[q][p]=1;
			}
		}
		else if(masaoFriends.find(i+1)!=masaoFriends.end())
		{
			gN++;
			for(int j=0;j<v.size();j++)
				if(masaoFriends.find(v[j])!=masaoFriends.end())
				{
					int p=distance(masaoFriends.begin(),masaoFriends.find(i+1));
					int q=distance(masaoFriends.begin(),masaoFriends.find(v[j]));
					G[p][q]=G[p][q]=1;
				}
		}
		E[distance(masaoFriends.begin(),masaoFriends.find(i+1))]=v.size();
	}

	/*printf("masaoFriends =");
	for(set<int>::iterator it=masaoFriends.begin();it!=masaoFriends.end();it++)
		printf("%d ",*it);
	printf("\n");
	for(int i=0;i<gN;i++)
	{
		for(int j=0;j<gN;j++)
			printf("%d ",G[i][j]);
		printf("\n");
	}*/
}

double rec(int pos,int left)
{
	//printf("rec(%d,%d)\n",pos,left);
	double &r=cache[pos][left];
	if(-1.0<r)
		;
	else if(left==0)
		r=1.0;
	else
	{
		r=0.0;
		vector<double> prob;
		for(int i=0;i<gN;i++)
			if(G[pos][i] && ((1<<i)&left))
				prob.push_back(rec(i,left^(1<<i)));
		sort(prob.begin(),prob.end());
		reverse(prob.begin(),prob.end());
		/*printf("prob=");
		for(int i=0;i<prob.size();i++)
			printf("%lf ",prob[i]);
		printf("\n");*/
		if(K<E[pos])
		{
			double p=1.0;
			for(int i=0;i<prob.size();i++)
			{
				r+=(p-C[E[pos]-i-1][K]/C[E[pos]][K])*prob[i];
				p=C[E[pos]-i-1][K]/C[E[pos]][K];
			}
		}
		else if(0<prob.size())
			r+=prob[0];
	}
	return r;
}

class FriendTour 
{
	public:
		double tourProbability(vector<string> input,int _K) 
		{
			K=_K;
			makeG(input);
			init();

			return rec(0,(1<<gN)-1-1);
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"2 3 4",
			"1 3 4",
			"1 2 4",
			"1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.2222222222222222; verify_case(0, Arg2, tourProbability(Arg0, Arg1)); }
		void test_case_1() { string Arr0[] = {"2 3 4",
			"1 3 4",
			"1 2 4",
			"1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.6666666666666666; verify_case(1, Arg2, tourProbability(Arg0, Arg1)); }
		void test_case_2() { string Arr0[] = {"3 2 4",
			"3 5 1",
			"5 2 1 4",
			"3 1 5",
			"3 2 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.3333333333333333; verify_case(2, Arg2, tourProbability(Arg0, Arg1)); }
		void test_case_3() { string Arr0[] = {"3 2 4",
			"3 5 1",
			"5 2 1 4",
			"3 1 5 6",
			"3 2 4",
			"4"}
			; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.3055555555555556; verify_case(3, Arg2, tourProbability(Arg0, Arg1)); }
			void test_case_4() { string Arr0[] = {"6 5 4 2",
				"1 6 3 5",
				"5 4 2",
				"3 1 5",
				"2 4 3 1 6",
				"1 2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.73125; verify_case(4, Arg2, tourProbability(Arg0, Arg1)); }

			// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	FriendTour ___test;
	___test.run_test(-1);
}
// END CUT HERE
