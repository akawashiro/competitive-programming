#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

LL DP[(1<<13)][2][15][15];

class PalindromePhrases 
{
	public:

		int n;
		vector<string> words;

		bool isPalindome(string s)
		{
			for(int i=0;i<s.size();i++)
				if(s[i]!=s[s.size()-1-i])
					return false;
			return true;
		}

		void printBit(int n,int len)
		{
			for(int i=len-1;0<=i;i--)
				if(n&(1<<i))
					printf("1");
				else
					printf("0");
		}

		LL rec(int left,int isLeft,int id,int len)
		{
			/*printf("rec(");
			printBit(left,n);
			printf(",%d,%d,%d)\n",isLeft,id,len);*/

			LL &r=DP[left][isLeft][id][len];
			if(r!=-1)
				;
			else if(isLeft)
			{
				r=0;
				int pos=words[id].size()-len;
				string s=words[id].substr(pos);
				if(isPalindome(s))
				{
					r++;
					//printf("+1\n");
				}
				for(int next=0;next<n;next++)
					if(left & (1<<next))
						if(len<words[next].size())
						{
							int i;
							for(i=0;i<len;i++)
								if(words[id][pos+i]!=words[next][words[next].size()-1-i])
									break;
							if(i==len)
								r+=rec(left^(1<<next),0,next,words[next].size()-i);
						}
						else
						{
							int i;
							for(i=0;i<words[next].size();i++)
								if(words[id][pos+i]!=words[next][words[next].size()-1-i])
									break;
							if(i==words[next].size())
								r+=rec(left^(1<<next),1,id,len-i);
						}
			}
			else
			{
				r=0;
				int pos=len-1;
				string s=words[id].substr(0,len);
				if(isPalindome(s))
				{
					r++;
					//printf("+1\n");
				}
				for(int next=0;next<n;next++)
					if(left & (1<<next))
						if(len<words[next].size())
						{
							int i;
							for(i=0;i<len;i++)
								if(words[id][i]!=words[next][len-1-i])
									break;
							if(i==len)
								r+=rec(left^(1<<next),1,next,words[next].size()-i);
						}
						else
						{
							int i;
							for(i=0;i<words[next].size();i++)
								if(words[id][pos-i]!=words[next][i])
									break;
							if(i==words[next].size())
								r+=rec(left^(1<<next),0,id,len-i);
						}
			}
			return r;
		}

		LL getAmount(vector <string> _words) 
		{
			words=_words;
			n=words.size();

			memset(DP,-1,sizeof(DP));
			LL ans=0;
			for(int i=0;i<n;i++)
				ans+=rec(((1<<n)-1)^(1<<i),1,i,words[i].size());
			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"a","ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, getAmount(Arg0)); }
		void test_case_1() { string Arr0[] = {"ab","bcd","efg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getAmount(Arg0)); }
		void test_case_2() { string Arr0[] = {"a", "bba", "abb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, getAmount(Arg0)); }
		void test_case_3() { string Arr0[] = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; verify_case(3, Arg1, getAmount(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	PalindromePhrases ___test;
	___test.run_test(-1);
}
// END CUT HERE
