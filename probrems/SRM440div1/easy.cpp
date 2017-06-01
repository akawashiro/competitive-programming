//this is copy
#include <vector>
#include <cmath>
using namespace std;

template<class T> 
T sqr(T x)
{
	return x*x;
}

class IncredibleMachine
{
	public:

	

		double gravitationalAcceleration(vector <int> x, vector <int> y, int T)
		{
			double F=1e20,L=0;
			for(int step=0;step<2000;step++)
			{
				double g=(F+L)/2.0;
				double v0=0,time=0;
				for(int i=0;i<x.size()-1;i++)
				{
					double xdif=abs(x[i]-x[i+1]);
					double ydif=abs(y[i]-y[i+1]);
					double v1=sqrt(sqr(v0)+2*ydif*g);
					double d=sqrt(sqr(xdif)+sqr(ydif));
					time+=2.0*d/(v0+v1);
					v0=v1;
				}
				if(time<T)
					F=g;
				else
					L=g;
			}
			return F;
		}
};

