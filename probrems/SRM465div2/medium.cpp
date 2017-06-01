#include <math.h>
#include <vector>
using namespace std;
typedef long long LL;

class TurretPlacement{
	public:

		LL com(int x1,int y1,int x2,int y2)
		{
			//printf("x1=%d y1=%d x2=%d y2=%d\n",x1,y1,x2,y2);
			double xDif=x1-x2,yDif=y1-y2;
			LL dist=(LL)(sqrt(xDif*xDif+yDif*yDif)*2);
			dist--;
			LL r=0;
			for(dist;0<dist;dist--)
				r+=dist;
			return r;
		}

		LL count(vector <int> x, vector <int> y)
		{
			LL ans=0;
			int n=x.size();
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					ans+=com(x[i],y[i],x[j],y[j]);
			return ans;
		}
};
