#include <vector>
#include <algorithm>
#include <functional>

class RoadOrFlightEasy{
	public:
		int minTime(int N, vector <int> roadTime, vector <int> flightTime, int K)
		{
			int n=roadTime.size();
			int time=0;
			for(int i=0;i<n;i++)
				time+=roadTime[i];
			vector<int> dif;
			for(int i=0;i<n;i++)
				dif.push_back(roadTime[i]-flightTime[i]);
			sort(dif,greater<int>());
			for(int i=0;i<K;i++)
				if(0<dif[i])
					time-=dif[i];
			return time;
		}
};
