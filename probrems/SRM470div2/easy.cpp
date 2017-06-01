#include <vector>
#include <algorithm>
using namespace std;

class LinearTravellingSalesman{
	public:
		int findMinimumDistance(vector <int> x, vector <int> y)
		{
			sort(x.begin(),x.end());
			sort(y.begin(),y.end());
			return x[x.size()-1]-x[0]+y[y.size()-1]-y[0];
		}
};
