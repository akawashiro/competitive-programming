#include <algorithm>
using namespace std;

class SameDigits
{
	public:
		int DP[2][1000+1];

		int howMany(int n, int k)
		{
			for(int left=0;left<=n;left++)
				for(int used=0;used<2;used++)
				{
					DP[used][left]=0;
					if(used==1 && left==0)
						DP[used][left]=1;
						
					for(int i=1;i<=min(left,k);i++)
					{
						if(i==k)
							DP[used][left]+=(9*DP[1][left-i]);
						else
							DP[used][left]+=(9*DP[used][left-i]);
						DP[used][left]%=44444444;
					}
				}

			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=DP[0][i];
				ans%=44444444;
			}
			return ans;
		}
};

