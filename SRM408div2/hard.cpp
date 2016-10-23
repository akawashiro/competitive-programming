#include <algorithm>

using namespace std;

class MarblesInABag
{
	public:

		double DP[2][4000+1];

		double getProbability(int redCount, int blueCount)
		{
			for(int R=0;R<=redCount;R++)
				for(int B=0;B<=blueCount;B++)
				{
					if((R+B)%2==0)
						continue;
					if(R==0)
						DP[R%2][B]=1.0;
					else if(B==0)
						DP[R%2][B]=0.0;
					else if(B==1)
						DP[R%2][B]=0.0;
					else
						DP[R%2][B]=(double)R/(double)(R+B)*DP[(R-1+2)%2][B-1]+(double)B/(double)(R+B)*DP[R%2][B-2];
					if(R==redCount && B==blueCount)
						return DP[R%2][B];
				}
		}
};

