#include <vector>
using namespace std;

class TheTournamentDivTwo{
	public:
		int find(vector <int> points)
		{
			int sum=0;
			for(int i=0;i<points.size();i++)
				sum+=points[i];
			if(sum%2==1)
				return -1;
			return sum/2;
		}
};
