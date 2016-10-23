#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[3][4][50+10][50+10][50+10];

class BoxesArrangement 
{
	public:

		int len;
		string boxes;

		int rec(int w,int n,int A,int B,int C)
		{
			int p=len-A-B-C;
			//printf("w=%d n=%d p=%d A=%d B=%d C=%d\n",w,n,p,A,B,C);
			//cout << s << endl;

			int &r=cache[w][n][A][B][C];

			if(r!=-1000)
				return r;
			else if(n==3)
				r=-100;
			else if(p==len)
			{
				r=0;
				//printf("w=%d n=%d\n",w,n);
			}
			else
			{
				r=-100;
				if(0<A)
				{
					int nn=(w==0)?n+1:1;
					int t=(boxes[p]=='A')?1:0;
					r=max(r,rec(0,nn,A-1,B,C)+t);
				}
				if(0<B)
				{
					int nn=(w==1)?n+1:1;
					int t=(boxes[p]=='B')?1:0;
					r=max(r,rec(1,nn,A,B-1,C)+t);
				}
				if(0<C)
				{
					int nn=(w==2)?n+1:1;
					int t=(boxes[p]=='C')?1:0;
					r=max(r,rec(2,nn,A,B,C-1)+t);
				}
			}

			return r;
		}

		int maxUntouched(string _boxes) 
		{
			boxes=_boxes;
			len=boxes.size();
			int A=0,B=0,C=0;
			for(int i=0;i<boxes.size();i++)
				if(boxes[i]=='A')
					A++;
				else if(boxes[i]=='B')
					B++;
				else
					C++;

			cout << endl;

			fill(&cache[0][0][0][0][0],&cache[2][3][59][59][59],-1000);
			int ans=rec(0,0,A,B,C);

			return (ans<0)?-1:ans;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arg0 = "AAABBBCCC"; int Arg1 = 6; verify_case(0, Arg1, maxUntouched(Arg0)); }
		void test_case_1() { string Arg0 = "AAAAAAAACBB"; int Arg1 = 7; verify_case(1, Arg1, maxUntouched(Arg0)); }
		void test_case_2() { string Arg0 = "CCCCCB"; int Arg1 = -1; verify_case(2, Arg1, maxUntouched(Arg0)); }
		void test_case_3() { string Arg0 = "BAACAABAACAAA"; int Arg1 = 5; verify_case(3, Arg1, maxUntouched(Arg0)); }
		void test_case_4() { string Arg0 = "CBBABA"; int Arg1 = 6; verify_case(4, Arg1, maxUntouched(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	BoxesArrangement ___test;
	___test.run_test(-1);
}
// END CUT HERE
