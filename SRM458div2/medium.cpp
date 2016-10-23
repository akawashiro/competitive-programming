#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;

class BouncingBalls{
	public:
		double expectedBounces(vector <int> x, int T)
		{
			double count=0;
			sort(x.begin(),x.end());
			int n=x.size();
			for(int dire=0;dire<(1<<n);dire++){
				vector<int> coll;
				for(int i=0;i<n;i++)
					if(dire & (1<<i))
						for(int j=i+1;j<n;j++)
							if(!(dire & (1<<j)))
								coll.push_back(x[j]-x[i]);
				sort(coll.begin(),coll.end());
				for(int i=0;i<coll.size();i++){
					if(coll[i]<=T*2)
						count++;
					else
						break;
				}
			}
			return count/pow(2,n);
		}
};
