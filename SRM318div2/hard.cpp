#include <algorithm>
using namespace std;

class SimplifiedDarts
{
	public:
		double DP[1000+1][3000+1];

		double tryToWin(int W, int N, int P1, int P2)
		{
			for(int time=N;0<=time;time--)
				for(int point=3000;0<=point;point--)
				{
					if(time==N && W<=point)
						DP[time][point]=100.0;
					if(time==N && point<W)
						DP[time][point]=0.0;
					if(time!=N)
					{
						DP[time][point]=0.0;
						if(point+2<=3000)
							DP[time][point]=max(DP[time][point],DP[time+1][point+2]*P1/100.0+DP[time+1][point]*(100-P1)/100.0);
						if(point+3<=3000)
							DP[time][point]=max(DP[time][point],DP[time+1][point+3]*P2/100.0+DP[time+1][point]*(100-P2)/100.0);
					}
				}
			return DP[0][0];
		}
};

