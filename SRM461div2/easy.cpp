#include <vector>
using namespace std;

class TrappingRabbit{
	public:
		int findMinimumTime(vector <int> trapX, vector <int> trapY)
		{
			int dist=2000;
			for(int i=0;i<trapX.size();i++){
				int a=trapX[i]-1+trapY[i]-1;
				dist=min(a,dist);
			}
			return dist;
		}
};
