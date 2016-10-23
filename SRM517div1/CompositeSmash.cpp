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
int isPrime[100000+10];

vector<pair<int,int> > primeFactor(int num) //first->prime,second->pow
{
	if(num==1)
	{
		vector<pair<int,int> > r;
		r.push_back(make_pair(1,1));
		return r;
	}
	else
	{
		vector<pair<int,int> > r;
		for(int i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				int p=0;
				while(num%i==0)
					num/=i,p++;
				r.push_back(make_pair(i,p));
			}
		}
		if(num!=1)
			r.push_back(make_pair(num,1));
		return r;
	}
}

class CompositeSmash 
{
	public:
		string thePossible(int N, int target) 
		{
			{
				for(int i=2;i<100000+10;i++)
					isPrime[i]=1;
				isPrime[0]=isPrime[1]=0;
				for(int i=2;i<100000+10;i++)
					if(isPrime[i])
						for(int j=i*2;j<100000+10;j+=i)
							isPrime[j]=0;
			}
			if(N<target)
				return "No";
			if(N==target || (N%target==0 && isPrime[target]))
			{
				cout<<"N==target || (N%target==0 && isPrime[target])"<<endl;
				return "Yes";
			}
			pair<int,int> p1,p2;
			if(1<primeFactor(N).size() || 1<primeFactor(target).size())
			{
				cout<<"1<primeFactor(N).size() || 1<primeFactor(target).size()"<<endl;
				return "No";
			}
			p1=primeFactor(N)[0];
			p2=primeFactor(target)[0];
			if(p1.first==p2.first && p2.second<3)
			{
				cout<<"p1.first==p2.first && p1.second==3"<<endl;
				return "Yes";
			}
			return "No";
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 517; int Arg1 = 47; string Arg2 = "Yes"; verify_case(0, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_1() { int Arg0 = 8; int Arg1 = 4; string Arg2 = "Yes"; verify_case(1, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_2() { int Arg0 = 12; int Arg1 = 6; string Arg2 = "No"; verify_case(2, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_3() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "No"; verify_case(3, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; string Arg2 = "Yes"; verify_case(4, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_5() { int Arg0 = 5858; int Arg1 = 2; string Arg2 = "Yes"; verify_case(5, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_6() { int Arg0 = 81461; int Arg1 = 2809; string Arg2 = "No"; verify_case(6, Arg2, thePossible(Arg0, Arg1)); }
		void test_case_7() { int Arg0 = 65536; int Arg1 = 256; string Arg2 = "No"; verify_case(7, Arg2, thePossible(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	CompositeSmash ___test;
	___test.run_test(-1);
}
// END CUT HERE
