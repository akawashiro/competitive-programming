#include <cstring>
#include <vector>
#define TOWER_MAX 250000

using namespace std;

class EqualTowers
{
	public:

		int n;
		vector<int> bricks;

		int cache[TOWER_MAX+1][50];

		int rec(int dif,int k)
		{
			if((k==n && dif!=0) || TOWER_MAX<dif)
				return -(1<<28);
			if(k==n && dif==0)
				return 0;
			if(cache[dif][k]!=-1)
				return cache[dif][k];

			int a=rec(dif+bricks[k],k+1);
			int b=rec(dif,k+1);
			int c=(dif<bricks[k])?rec(bricks[k]-dif,k+1)+dif:rec(dif-bricks[k],k+1)+bricks[k];

			return cache[dif][k]=max(a,max(b,c));
		}

		int height(vector <int> _bricks)
		{
			bricks=_bricks;
			n=bricks.size();
			memset(cache,-1,sizeof(cache));
			int ans=rec(0,0);

			return (ans<=0)?-1:ans;
		}
};

