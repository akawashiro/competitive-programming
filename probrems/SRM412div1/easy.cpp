#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

class ForbiddenStrings
{
	public:
		long long countNotForbidden(int n)
		{
			if(n==1)	return 3;

			n-=2;
			vector<LL> DP(9,1);
			for(int i=0;i<n;i++)
			{
				vector<LL> v(9,0);
				v[0]=DP[0]+DP[3]+DP[6];
				v[1]=DP[0]+DP[3];
				v[2]=DP[0]+DP[6];

				v[3]=DP[1]+DP[4];
				v[4]=DP[1]+DP[4]+DP[7];
				v[5]=DP[4]+DP[7];

				v[6]=DP[2]+DP[8];
				v[7]=DP[5]+DP[8];
				v[8]=DP[2]+DP[5]+DP[8];

				DP=v;
			}
			LL ans=0;
			for(int i=0;i<9;i++)
				ans+=DP[i];
			return ans;
		}
};
