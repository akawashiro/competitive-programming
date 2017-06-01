#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class TheMoviesLevelThreeDivTwo
{
	public:
		int n;
		vector<int> timeJ,timeB;
		queue<int> qJ,qB;

		bool check()
		{
			int tJ=0,tB=0;
			int wJ=0,wB=0;

			while(!qJ.empty() && !qB.empty() && wJ!=n && wB!=n)
			{
				if(tJ+timeJ[qJ.front()] < tB+timeB[qB.front()])
				{
					tJ+=timeJ[qJ.front()];
					wJ++;
					qB.push(qJ.front());
					qJ.pop();

					continue;
				}

				if(tB+timeB[qB.front()] < tJ+timeJ[qJ.front()])
				{
					tB+=timeB[qB.front()];
					wB++;
					qJ.push(qB.front());
					qB.pop();

					continue;
				}

				else
				{
					tJ+=timeJ[qJ.front()];
					tB+=timeB[qB.front()];
					wJ++,wB++;
					qB.push(qJ.front());
					qJ.push(qB.front());
					qJ.pop();
					qB.pop();

					continue;
				}
			}
			return (n==wJ || n==wB);
		}

		int find(vector<int> _timeJ,vector<int> _timeB)
		{
			timeJ=_timeJ;
			timeB=_timeB;
			n=timeJ.size();

			int ans=0;
			for(int dis=0;dis<(1<<n);dis++)
			{
				while(!qJ.empty())
					qJ.pop();
				while(!qB.empty())
					qB.pop();
				for(int i=0;i<n;i++)
					if(dis & (1<<i))
						qJ.push(i);
					else
						qB.push(i);
				if(check())
					ans++;
			}

			return ans;
		}
};
