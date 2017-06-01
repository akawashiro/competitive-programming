//理解したような気になった
#include <math.h>
using namespace std;
typedef long long LL;

class ProductTriplet{
	public:

		LL f(LL x0,LL y1,LL y2,LL z1,LL z2)
		{
			z1=max(z1,x0*x0+1);
			if(z2<z1)
				return 0;
			LL floor=max(y1,(z1-x0+1)/x0);
			LL ceil =min(y2,z2/x0);
			return max(0,floor-ceil);
		}

		LL countTriplets(int minx, int maxx, int miny, int maxy, int minz, int maxz)
		{
			LL x1=minx,x2=maxx,y1=miny,y2=maxy,z1=minz,z2=maxz,count=0;

			for(LL x0=x1;x0<=x2 && x0*x0<z2;x0++)
				count+=f(x0,y1,y2,z1,z2);
			for(LL y0=y1;y0<=y2 && y0*y0<z2;y0++)
				count+=f(y0,x1,x2,z1,z2);
			for(LL sq=max(x1,y1);sq<=min(x2,y2) && sq*sq<=z2;sq++)
				if(z1 <= sq*sq)
					count++;
			return count;
		}
};
