#include <vector>
using namespace std;
typedef long long LL;

class FIELDDiagrams
{
	public:
		LL countDiagrams(int fie)
		{
			LL DP[31][31];
			memset(DP,0,sizeof(DP));
			DP[1][0]=1;
			DP[1][1]=1;

			for(int i=2;i<=30;i++)
				for(int j=0;j<=i;j++)
					for(int k=0;k<=min(j,i-1);k++)
						DP[i][j]+=DP[i-1][k];

			LL ans=0;
			for(int i=1;i<=fie;i++)
				ans+=DP[fie][i];
			return ans;
		}
};
