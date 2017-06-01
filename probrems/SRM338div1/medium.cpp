#include <cstdio>

using namespace std;

class RandomSwaps
{
	public:
		double getProbability(int arrayLength, int swapCount, int a, int b)
		{
			double inA=1.0,inOther=0.0,n=arrayLength;
			double nC2=n*(n-1)/2;

			for(int i=0;i<swapCount;i++)
			{
				double a,o;
				a=inA*(nC2-(n-1))/nC2+inOther*1.0/nC2;
				o=inA*(n-1)/nC2+inOther*(nC2-1.0)/nC2;
				inA=a,inOther=o;
			}
			if(a==b)
				return inA;
			else
				return inOther/(n-1);
		}
};

