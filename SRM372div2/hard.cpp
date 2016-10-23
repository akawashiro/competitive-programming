#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,pair<int,int> > D;

D makeD(int a,int b,int c)
{
	return make_pair(a,make_pair(b,c));
}

class RainyDay
{
	public:

		int n;
		int wetTime[50][50];
		string path,forecast;

		int rainy(int t,int p)
		{
			return (path[p]=='.' && forecast[t%n+p]=='R')?1:0;
		}

		int minimumRainTime(string _path, string _forecast)
		{
			int home,first,mv;
			path=_path;
			forecast=_forecast+_forecast;
			n=path.size();			

			for(int i=0;i<n;i++)
			{
				if(path[i]=='H')
					home=i;
				if(path[i]=='Y')
					first=i;
			}
			mv=(first<home)?1:-1;

			for(int i=0;i<50;i++)
				for(int j=0;j<50;j++)
					wetTime[i][j]=(1<<28);

			priority_queue<D,vector<D>,greater<D> > que;
			que.push(makeD(0,0,first));

			while(!que.empty())
			{
				int w=que.top().first;
				int t=que.top().second.first,p=que.top().second.second;
				que.pop();

				if(t<250 && 0<=p && p<n && w<wetTime[t][p])
				{
					wetTime[t][p]=w;
					int ww;
					ww=w+rainy(t,p)+rainy(t+1,p);
					que.push(makeD(ww,(t+1)%n,p));
					
					ww=w+rainy(t,p+1)+rainy(t+1,p+1);
					que.push(makeD(ww,(t+1)%n,p+1));
					
					ww=w+rainy(t,p-1)+rainy(t+1,p-1);
					que.push(makeD(ww,(t+1)%n,p-1));
				}
			}

			int minWet=(1<<28);
			for(int i=0;i<50;i++)
				minWet=min(minWet,wetTime[i][home]);
			return minWet;	
		}
};

