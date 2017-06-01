#include <vector>
#include <climits>
#include <math.h>
using namespace std;

class BuyingFlowers
{
	public:
		int buy(vector <int> roses, vector <int> lilies)
		{
			int ans=INT_MAX;
			int n=roses.size();
			for(int select=1;select<(1<<n);select++)
			{
				int r=0,l=0;
				for(int i=0;i<n;i++)
					if(select & (1<<i))
					{
						r+=roses[i];
						l+=lilies[i];
					}
				if(1<abs(r-l))
					continue;
				int R;
				for(R=1;R<=(r+l)/R;R++)
					if((r+l)%R==0)
						ans=min(ans,abs(R-(r+l)/R));
			}
			return (ans==INT_MAX) ? -1 : ans;
		}
};
