//桁溢れ注意
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

class MaxTriangle
{
	public:
		double calculateArea(int _A, int _B)
		{
			LL A=_A; LL B=_B;
			double ans=-1;
			for(LL x1=0;x1*x1<=A;x1++)
			{
				LL y1=(int)sqrt(A-x1*x1);
				if(y1*y1!=A-x1*x1)
					continue;
				for(LL x2=0;x2*x2<=B;x2++)
				{
					LL y2=(int)sqrt(B-x2*x2);
					if(y2*y2!=B-x2*x2)
						continue;
					//printf("%d %d %d %d \n",x1,y1,x2,y2);
					LL a=A*B;
					LL b1=x1*x2+y1*y2;		b1*=b1;
					LL b2=x1*x2*(-1)+y1*y2;	b2*=b2;
					LL b3=x1*x2+y1*y2*(-1);	b3*=b3;
					LL b=min(b1,min(b2,b3));
					ans=max(ans,sqrt((double)(a-b))/2);
				}
			}
			return ans;
		}
};
