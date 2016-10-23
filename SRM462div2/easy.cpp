#include <vector>
using namespace std;

class Archery{
	public:
		double expectedPoints(int N, vector <int> ringPoints)
		{
			double ans=0;
			for(int i=0;i<=N;i++){
				int a=i+1;
				ans+=ringPoints[i]*(a*a-i*i);
			}
			ans/=(double)(N+1)*(N+1);
			return ans;
		}
};
