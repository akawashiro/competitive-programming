//this is copy of ACRush
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class ShufflingMachine
{
	public:
		double stackDeck(vector<int> A,int m,vector<int> R,int K)
		{
			int C[60];
			memset(C,0,sizeof(C));
			int n=A.size();
			vector<int> S;
			for(int i=0;i<n;i++)
				S.push_back(i);
			for(int step=0;step<m;step++)
			{
				vector<int> S0=S;
				for(int i=0;i<n;i++)
					S[A[i]]=S0[i];
				for(int i=0;i<R.size();i++)
					C[S[R[i]]]++;
			}

			sort(C,C+n);
			reverse(C,C+n);
			double result=0;
			for(int i=0;i<K;i++)
				result+=C[i];
			result/=(double)(m);
			return result;
		}
};

