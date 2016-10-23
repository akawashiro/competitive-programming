#include <cmath>

class TestBettingStrategy
{
	public:

		double DP[55][11][2010];

		double winProbability(int initSum, int goalSum, int rounds, int _prob)
		{
			for(int i=0;i<55;i++)
				for(int j=0;j<11;j++)
					for(int k=0;k<2010;k++)
						DP[i][j][k]=0.0;

			double prob=(double)_prob/100.0,ans=0.0;
			DP[0][10][initSum]=1.0;

			for(int r=0;r<=rounds;r++)
				for(int b=0;b<11;b++)
					for(int now=0;now<2010;now++)
						if(goalSum<=now)
							ans+=DP[r][b][now],DP[r][b][now]=0.0;
						else if(r!=rounds)
						{
							int bet=(b==10)?1:pow(2,(b+1));
							if(bet<=now)
							{
								DP[r+1][10][now+bet]+=DP[r][b][now]*prob;
								DP[r+1][(b==10)?0:b+1][now-bet]+=DP[r][b][now]*(1.0-prob);
							}
						}

			return ans;
		}
};

