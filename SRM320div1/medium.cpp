#include <sstream>
#include <vector>

using namespace std;

class ContestSchedule
{
	public:

		int n;
		double cache[55];
		vector<int> start;
		vector<int> end;
		vector<double> winExp;

		double rec(int lastContest)
		{
			double &r=cache[lastContest];
			if(!(r<0))
				return r;

			r=0.0;
			for(int i=0;i<n;i++)
				if(end[lastContest]<=start[i])
					r=max(r,winExp[i]+rec(i));
			return r;
		}

		double expectedWinnings(vector<string> contests)
		{
			contests.push_back("-1 0 0");
			n=contests.size();
			for(int i=0;i<n;i++)
			{
				cache[i]=-1.0;
				stringstream ss(contests[i]);
				int s,e;
				double w;
				ss >> s >> e >> w;
				w/=100.0;
				start.push_back(s);
				end.push_back(e);
				winExp.push_back(w);
			}

			return rec(n-1);
		}
};

