#include <cmath>
#include <vector>

using namespace std;

class PolyMove
{
	public:

		double getInc(double x1,double y1,double x2,double y2)
		{
			double xd=x1-x2,yd=y1-y2;
			return sqrt(xd*xd+yd*yd)/2.0;
		}

		double addedArea(vector <int> _x, vector <int> _y)
		{
			int n=_x.size();
			vector<double> x(n),y(n),inc(n);
			for(int i=0;i<n;i++)
				x[i]=_x[i],y[i]=_y[i];
			for(int i=1;i<n-1;i++)
				inc[i]=getInc(x[(i-1+n)%n],y[(i-1+n)%n],x[(i+1+n)%n],y[(i+1+n)%n]);

			double ans;
			double DP[55];
			DP[n]=0.0;
			DP[n-1]=inc[n-1];
			for(int i=n-2;1<=i;i--)
				DP[i]=max(DP[i+2]+inc[i],DP[i+1]);
			ans=DP[1];
			DP[n]=0.0;
			DP[n-1]=0.0;
			for(int i=n-2;0<=i;i--)
				DP[i]=max(DP[i+2]+inc[i],DP[i+1]);
			ans=max(ans,DP[0]);

			return ans;
		}
};

