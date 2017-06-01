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
typedef long long LL;

class SPartition 
{
	public:
		long long getCount(string input) 
		{
			int n=input.size()/2;
			map<string,LL> d1,d2;
			string fs=input.substr(0,n);
			string bs=input.substr(n,n);
			string s(n,'#'),t(n,'#');
			for(int m=0;m<1<<n;m++){
				int a=0,b=0,j;
				for(j=0;j<n;j++)
					if(m&(1<<j)){
						s[a]=fs[j];
						a++;
					}else{
						t[b]=fs[j];
						b++;
					}
				for(j=0;j<min(a,b);j++)
					if(s[j]!=t[j])
						break;
				if(j==a){
					d1[t.substr(a,b-a)]++;
					//cout<<"-"<<t.substr(a,b-a)<<endl;
				}			
			}
			for(int m=0;m<1<<n;m++){
				int a=0,b=0,i,j;
				for(j=0;j<n;j++)
					if(m&(1<<j)){
						s[a]=bs[j];
						a++;
					}else{
						t[b]=bs[j];
						b++;
					}
				for(i=a-1,j=b-1;0<=i&&0<=j;i--,j--)
					if(s[i]!=t[j])
						break;
				if(i==-1){
					d2[t.substr(0,b-a)]++;
					//cout<<s.substr(0,a)<<"--"<<t.substr(0,b)<<endl;
					//cout<<t.substr(0,b-a)<<endl;
				}			
			}
			LL ans=0;
			for(map<string,LL>::iterator it=d1.begin();it!=d1.end();it++){
				//cout<<(*it).first<<"="<<(*it).second<<"="<<d2[(*it).first]<<endl;
				if((*it).first=="")
					ans+=(*it).second*d2[(*it).first];
				else
					ans+=(*it).second*d2[(*it).first]*2;
			}
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arg0 = "oooooooooooooooooooooooooooooooooooooooo"; long long Arg1 = 2LL; verify_case(0, Arg1, getCount(Arg0)); }
		void test_case_1() { string Arg0 = "oooxxx"; long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
		void test_case_2() { string Arg0 = "xoxxox"; long long Arg1 = 4LL; verify_case(2, Arg1, getCount(Arg0)); }
		void test_case_3() { string Arg0 = "xo"; long long Arg1 = 0LL; verify_case(3, Arg1, getCount(Arg0)); }
		void test_case_4() { string Arg0 = "ooooxoox"; long long Arg1 = 8LL; verify_case(4, Arg1, getCount(Arg0)); }
		void test_case_5() { string Arg0 = "ooxxoxox"; long long Arg1 = 8LL; verify_case(5, Arg1, getCount(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	SPartition ___test;
	___test.run_test(-1);
}
// END CUT HERE
