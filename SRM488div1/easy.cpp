#include <vector>
using namespace std;

class TheBoredomDivOne
{
	public:
		double find(int n, int m)
		{
			vector<double> e(m+1);
			double all=n+m;
			e[0]=0;
			e[1]=all/2;
			for(int i=2;i<=m;i++)
			{
				double t=all*(all-1);
				double j=i;
				double p0=(all-j)*(all-j-1)/t;
				double p1=(all-j)*i*2/t;
				double p2=j*(j-1)/t;
				e[i]=(p1*e[i-1]+p2*e[i-2]+1)/(1-p0);
			}
			return e[m];
		}
};
