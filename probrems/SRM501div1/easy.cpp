#include <cmath>
#include <algorithm>

using namespace std;

class FoxPlayingGame
{
	public:
		double theMax(int nA, int nB, int paramA, int paramB)
		{
			double sA=(double)paramA/1000.0;
			double sB=(double)paramB/1000.0;
			double cur=sA*nA,bes=cur;
			for(int i=0;i<nB;i++,cur*=sB)
				best=max(best,cur);
			return best;
		}
};
