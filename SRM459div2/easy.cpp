#include <math.h>
using namespace std;

class RecursiveFigures
{
	public:
		double getArea(int side, int K)
		{
			double a=side;
			double S=0;
			S+=(a/2)*(a/2)*M_PI;
			a=a/sqrt(2);
			for(int i=1;i<K;i++){
				S-=a*a;
				S+=(a/2)*(a/2)*M_PI;
				a=a/sqrt(2);
			}
			return S;
		}
};
