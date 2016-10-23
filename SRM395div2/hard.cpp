#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class TriviaGame
{
	public:

		int DP[50+1][50];

		int maximumScore(vector<int> points, int tokensNeeded, vector<int> bonuses)
		{
			int n=points.size();
			for(int i=0;i<n+1;i++)
				for(int j=0;j<tokensNeeded;j++)
					DP[i][j]=-(1<<28);
			
			DP[0][0]=0;
			for(int time=0;time<n;time++)
				for(int token=0;token<tokensNeeded;token++)
					if(DP[time][token]!=-(1<<28))
					{
						DP[time+1][token]=max(DP[time+1][token],DP[time][token]-points[time]);
						if(token+1==tokensNeeded)
							DP[time+1][0]=max(DP[time+1][0],DP[time][token]+points[time]+bonuses[time]);
						else
							DP[time+1][token+1]=max(DP[time+1][token+1],DP[time][token]+points[time]);
					}

			int ans=0;
			for(int i=0;i<tokensNeeded;i++)
				ans=max(ans,DP[n][i]);

			return ans;
		}
};

