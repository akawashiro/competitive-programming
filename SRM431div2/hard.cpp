#include <cmath>

class SumAndProduct
{
	public:
		int smallestSet(int S, int P)
		{
			if(S==P)
				return 1;
			double s=S,p=P;
			for(int n=2;n<=100;n++)
				if(p<pow(s/n,n)+1e-9)
					return n;
			return -1;
		}
};
