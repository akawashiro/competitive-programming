#include <math.h>
#include <vector>
using namespace std;

class SilverDistance{
	public:
		int minSteps(int sx, int sy, int gx, int gy)
		{
			int step=0;
			int difx=abs(sx-gx),dify=abs(sy-gy);
			if((difx+dify)%2==1){
				step++;
				dify=abs((sy+1)-gy);
			}
			step+=max(difx,dify);
			return step;
		}
};
