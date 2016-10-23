#include <vector>
#include <cmath>
#include <utility>
#include <list>
using namespace std;

class LaserShooting
{
	public:
		double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2)
		{
			double ans=0;
			for(int i=0;i<x.size();i++)
			{
				double a=atan((double)y1[i]/(double)x[i]);
				double b=atan((double)y2[i]/(double)x[i]);
				ans+=(max(a,b)-min(a,b))/M_PI;
			}
			return ans;
		}
};
