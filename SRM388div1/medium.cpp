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

using namespace std;

class GuitarConcert 
{
	public:

		vector<string> comp(vector<string> vs1,vector<string> vs2)
		{
			//sort(vs1.begin(),vs1.end());
			//sort(vs2.begin(),vs2.end());
			if(vs1.size()==vs2.size())
				return (vs1<vs2)?vs1:vs2;
			else
				return (vs1.size()<vs2.size())?vs1:vs2;
		}

		vector <string> buyGuitars(vector <string> guitarNames, vector <string> guitarSongs) 
		{
			int nG=guitarNames.size(),nS=guitarSongs[0].size(),maxPlay=0;

			//printf("nG=%d nS=%d\n",nG,nS);

			vector<string> ans;
			for(int use=0;use<(1<<nG);use++)
			{
				set<int> se;
				vector<string> vs;
				for(int i=0;i<nG;i++)
					if(use & (1<<i))
					{
						vs.push_back(guitarNames[i]);
						for(int j=0;j<nS;j++)
							if(guitarSongs[i][j]=='Y')
								se.insert(j);
					}
				sort(vs.begin(),vs.end());

				//for(int i=0;i<vs.size();i++)
					//printf("%s ",vs[i].c_str());
				//printf("--%d\n",se.size());

				if(maxPlay<se.size())
				{
					maxPlay=se.size();
					ans=vs;
				}
				else if(maxPlay==se.size())
					ans=comp(ans,vs);
				else
					;
			}
			return ans;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
		void test_case_0() { string Arr0[] = {"GIBSON","FENDER", "TAYLOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNYYN", "NNNYY", "YYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"TAYLOR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, buyGuitars(Arg0, Arg1)); }
		void test_case_1() { string Arr0[] = {"GIBSON", "CRAFTER", "FENDER", "TAYLOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYNN", "NNNYY", "YYNNY", "YNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, buyGuitars(Arg0, Arg1)); }
		void test_case_2() { string Arr0[] = {"AB", "AA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN", "YN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, buyGuitars(Arg0, Arg1)); }
		void test_case_3() { string Arr0[] = {"FENDER", "GIBSON", "CRAFTER", "EPIPHONE", "BCRICH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYNNYNN", "YYYNYNN", "NNNNNYY", "NNYNNNN", "NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"BCRICH", "CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, buyGuitars(Arg0, Arg1)); }
		void test_case_4() { string Arr0[] = {"GIBSON","FENDER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, buyGuitars(Arg0, Arg1)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	GuitarConcert ___test;
	___test.run_test(-1);
}
// END CUT HERE
