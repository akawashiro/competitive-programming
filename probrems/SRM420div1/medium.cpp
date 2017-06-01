#include <algorithm>

using namespace std;

class RedIsGood 
{
	public:
	double getProfit(int R, int B) 
	{
		double DP[2][5010];
		for(int i=0;i<=B+1;i++)
			DP[(R+1)%2][i]=0.0;
		for(int r=R;0<=r;r--)
		{
			for(int b=B;0<=b;b--)
			{
				double red=(double)(R-r)/(double)((R+B)-(r+b));
				double a=red*DP[(r+1)%2][b]+(1.0-red)*DP[r%2][b+1];
				DP[r%2][b]=max((double)r-b,a);
			}
			DP[r%2][B+1]=0.0;
		}
		return DP[0][0];
	}
};

