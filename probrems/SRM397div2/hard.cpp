#include <cstring>
#include <vector>

using namespace std;

class CollectingMarbles
{
	public:

		int m,bC;
		vector<int> mW;
		int cache[(1<<13)][21][10];

		int rec(int marble,int cur,int left)
		{
			if(cache[marble][cur][left]!=-1)
				return cache[marble][cur][left];
			if(marble==0 || (cur==0 && left==0))
				return cache[marble][cur][left]=0;

			int r=(left!=0)?rec(marble,bC,left-1):0;
			for(int i=0;i<m;i++)
				if(marble & (1<<i) && mW[i]<=cur)
					r=max(r,rec(marble^(1<<i),cur-mW[i],left)+1);

			return cache[marble][cur][left]=r;
		}

		int mostMarbles(vector <int> marblesWeights, int bagCapacity, int numberOfBags)
		{
			bC=bagCapacity,m=marblesWeights.size();
			mW=marblesWeights;

			memset(cache,-1,sizeof(cache));
			return rec((1<<m)-1,bagCapacity,numberOfBags-1);
		}
};

