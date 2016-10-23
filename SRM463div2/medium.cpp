#include <vector>
#include <algorithm>
using namespace std;

class RabbitNumbering{
	public:
		int theCount(vector <int> maxNumber)
		{
			long long ways=1;
			int n=maxNumber.size();
			sort(maxNumber.begin(),maxNumber.end());
			for(int i=0;i<n;i++){
				//printf("ways=%lld\n",ways);
				ways*=(maxNumber[i]-i);
				if(ways<0)
					ways=0;
				ways%=1000000007;
			}
			return ways;
		}
};
