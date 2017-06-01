#include <vector>
using namespace std;

class AverageAverage{
		public:
				double average(vector<int> numlist);
};

double AverageAverage::average(vector<int> numlist)
{
		double ans=0;
		for(int i=0;i<numlist.size();i++)
				ans+=(double)numlist[i];
		ans/=(double)numlist.size();
		return ans;
}

