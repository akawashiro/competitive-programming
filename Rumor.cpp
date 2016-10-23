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
#include <queue>

using namespace std;

class Rumor 
{
	public:
		int getMinimum(string knowledge, vector <string> graph) 
		{
			int n=knowledge.size();
			set<string> se;
			queue<string> sque;
			queue<int> tque;
			string bs=knowledge;
			string es=string(n,'3');
			for(int i=0;i<n;i++)
				bs[i]=(bs[i]=='Y')?'3':'0';
			sque.push(bs);
			tque.push(0);
			int ans=-1;
			while(!sque.empty()){
				string s=sque.front();
				int t=tque.front();
				//cout<<s<<" "<<t<<endl;
				sque.pop();
				tque.pop();
				if(s==es){
					ans=t;
					break;
				}
				if(se.find(s)!=se.end())
					continue;
				se.insert(s);
				for(int m=0;m<(1<<n);m++){
					string ns=s;
					for(int i=0;i<n;i++)
						for(int j=0;j<n;j++)
							if(m&(1<<i)){
								if(graph[i][j]=='Y'&&(s[i]-'0')%2==1
										&&(ns[j]-'0')%2!=1){
									ns[j]++;
								}
							}else{
								if(graph[i][j]=='Y'&&'2'<=s[i]&&ns[j]<'2'){
									ns[j]+=2;
								}
							}
					if(se.find(ns)==se.end()){
						sque.push(ns);
						tque.push(t+1);
					}
				}
			}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arg0 = "YNN"; string Arr1[] = {"NYN"
			,"NNY"
				,"NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
		void test_case_1() { string Arg0 = "YNNY"; string Arr1[] = {"NYYN"
			,"YNNY"
				,"YNNY"
				,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
		void test_case_2() { string Arg0 = "YYYY"; string Arr1[] = {"NYNN"
			,"YNYN"
				,"NYNY"
				,"NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
		void test_case_3() { string Arg0 = "YYYYYN"; string Arr1[] = {"NYYYYN"
			,"YNYYYN"
				,"YYNYYN"
				,"YYYNYN"
				,"YYYYNN"
				,"NNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
		void test_case_4() { string Arg0 = "NNNY"; string Arr1[] = {"NNNN"
			,"YNNN"
				,"YNNN"
				,"NYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }
		void test_case_5() { string Arg0 =  "NNNNNNNYYY"; string Arr1[] = {"NYNNYNNYNN"
			,"NNYNYNNNNY"
				,"YYNNNYNNNN"
				,"YNNNYNYNNN"
				,"NNYNNYNNYN"
				,"NNNNYNNNYY"
				,"NYNYNYNNNN"
				,"NNNNNNYNYY"
				,"NNNYNNNYNY"
				,"NYYNNNNYNN"}
			; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(5, Arg2, getMinimum(Arg0, Arg1)); }

			// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	Rumor ___test;
	___test.run_test(-1);
}
// END CUT HERE
