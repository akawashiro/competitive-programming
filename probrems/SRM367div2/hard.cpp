#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

typedef long long LL;
using namespace std;

class ProgrammingDevice
{
	public:

		int n;
		LL maxData;
		LL cache[50];
		vector<pair<int,int> > data;

		LL rec(int s)
		{
			if(s==n)
				return 0;
			if(cache[s]!=-1)
				return cache[s];
			cache[s]=LLONG_MAX;
			for(int e=s;e<n;e++)
			{
				LL r=0;
				LL d=data[e].first+data[e].second-data[s].first;
				r=d/maxData+(d%maxData==0)?0:1+rec(e+1);

				cache[s]=min(cache[s],r);
			}
			return cache[s];
		}

		int minPackets(vector <int> offset, vector <int> size, int _maxData)
		{
			n=offset.size();
			maxData=_maxData;
			for(int i=0;i<n;i++)
				data.push_back(make_pair(offset[i],size[i]));
			sort(data.begin(),data.end());

			return rec(0);
		}
};

