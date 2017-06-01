#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class SpreadingNews
{
	public:

		vector<int> company;
		int n;

		int rec(int index)
		{
			vector<int> sub;
			for(int i=0;i<n;i++)
				if(company[i]==index)
					sub.push_back(rec(i));

			sort(sub.begin(),sub.end(),greater<int>());
			int r=0;

			for(int i=0;i<sub.size();i++)
				r=max(r,i+sub[i]);

			return r+1;
		}

		int minTime(vector <int> supervisors)
		{
			company=supervisors;
			n=company.size();

			return rec(0)-1;
		}
};

