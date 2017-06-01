#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Nisoku{
	public:
		double theMax(vector <double> cards)
		{
			int n=cards.size();
			double ans=0,tmp;
			sort(cards.begin(),cards.end());
			for(int i=0;i*2<=n;i++){
				tmp=1;
				for(int j=0;j<i;j++)
					tmp*=cards[j]+cards[2*i-1-j];
				for(int j=2*i;j<n;j++)
					tmp*=cards[j];
				ans=max(tmp,ans);
			}
			return ans;
		}
};
