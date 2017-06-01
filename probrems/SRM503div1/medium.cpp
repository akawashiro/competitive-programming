#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

class KingdomXCitiesandVillages 
{
	public:

		int n,m;
		double dist[100][100];

		double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) 
		{
			n=cityX.size(),m=villageX.size();
			for(int i=0;i<n+m;i++)
				for(int j=0;j<n+m;j++)
				{
					double xF=(i<n)?cityX[i]:villageX[i-n];
					double yF=(i<n)?cityY[i]:villageY[i-n];
					double xT=(j<n)?cityX[j]:villageX[j-n];
					double yT=(j<n)?cityY[j]:villageY[j-n];
					double xD=xT-xF,yD=yT-yF;
					dist[i][j]=sqrt(xD*xD+yD*yD);
				}

			double ans=0.0;
			for(int picked=n;picked<n+m;picked++)
			{
				double minToCity=dist[picked][0];
				for(int i=0;i<n;i++)
					minToCity=min(minToCity,dist[picked][i]);
				vector<double> candiate;
				for(int i=n;i<n+m;i++)
					if(i!=picked && dist[picked][i]<minToCity)
						candiate.push_back(dist[picked][i]);
				candiate.push_back(minToCity);
				sort(candiate.begin(),candiate.end());

				/*for(int i=0;i<(int)candiate.size();i++)
					printf("%2.2f ",candiate[i]);
				cout << endl;*/

				double prob=1.0;
				double d=2.0;
				for(int i=0;i<(int)candiate.size();i++)
				{
					if(i!=candiate.size()-1)
						ans+=candiate[i]*prob*1.0/d;
					else
						ans+=candiate[i]*prob;
					prob-=prob*1.0/d;
					d+=1.0;
				}
			}

			return ans;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.5; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
			void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,7,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
			void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 4.166666666666667; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

			// END CUT HERE


		};

		// BEGIN CUT HERE
		int main() {
			KingdomXCitiesandVillages ___test;
			___test.run_test(-1);
		}
		// END CUT HERE
