#include <vector>
#include <limits.h>

using namespace std;
typedef long long LL;

class TheProduct
{
	public:
		LL maxProduct(vector <int> numbers, int k, int maxDist)
		{
			LL DP[2][50][11]; //[min/max][first][left+first]
			int n=numbers.size();
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<k;j++)
				{
					DP[0][i][j]=LLONG_MAX;
					DP[1][i][j]=LLONG_MIN;
					if(j==0)
					{
						DP[0][i][j]=numbers[i];
						DP[1][i][j]=numbers[i];
					}
				}
			}

			for(int j=1;j<k;j++)
			{
				for(int i=0;i<n;i++)
				{
					for(int m=1; m<=maxDist && i+m+j<=n; m++)
					{
						LL a = ((0<=numbers[i]) ? DP[0][i+m][j-1] : DP[1][i+m][j-1] );
						DP[0][i][j]=min(a*numbers[i],DP[0][i][j]);

						a = ((0<=numbers[i]) ? DP[1][i+m][j-1] : DP[0][i+m][j-1] );
						DP[1][i][j]=max(a*numbers[i],DP[1][i][j]);
					}
				}
			}

			LL ans=LLONG_MIN;
			for(int i=0;i+k<=n;i++)
				ans=max(ans,DP[1][i][k-1]);


			return ans;
		}
};
