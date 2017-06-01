#include <algorithm>
#include <vector>

using namespace std;

class InsertSort
{
	public:
		int calcMinimalCost(vector<int> theArray)
		{
			int DP[50];
			int n=theArray.size();
			int a=0;

			for(int i=0;i<n;i++)
			{
				DP[i]=theArray[i];
				for(int j=0;j<i;j++)
					if(theArray[j]<=theArray[i])
						DP[i]=max(DP[i],DP[j]+theArray[i]);
				a=max(a,DP[i]);
			}

			int ans=0;
			for(int i=0;i<n;i++)
				ans+=theArray[i];
			ans-=a;

			return ans;
		}
};

