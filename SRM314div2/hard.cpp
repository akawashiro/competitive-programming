#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class GrasslandFencer
{
	public:

		vector<int> fences;
		double cache[(1<<16)];
		int n;

		double heron(int _a,int _b,int _c)
		{
			int d[3];
			d[0]=_a,d[1]=_b,d[2]=_c;
			sort(d,d+3);
			if(d[0]+d[1]<=d[2])
				return 0;

			double a=_a,b=_b,c=_c;
			double s=(a+b+c)/2.0;
			return sqrt(s*(s-a)*(s-b)*(s-c));
		}

		int popCount(int mask)
		{
			int r=0;
			for(int i=0;i<20;i++)
				if(mask & (1<<i))
					r++;
			return r;
		}
		
		double rec(int mask)
		{
			double &r=cache[mask];
			if(r!=-1)
				;
			else if(popCount(mask)<3)
				r=0.0;
			else
				for(int i=0;i<n;i++)
					if(mask & (1<<i))
						for(int j=i+1;j<n;j++)
							if(mask & (1<<j))
								for(int k=j+1;k<n;k++)
									if(mask & (1<<k))
									{
										int m=(mask & (~(1<<i)) & (~(1<<j)) & (~(1<<k)));
										r=max(r,heron(fences[i],fences[j],fences[k])+rec(m));
									}

			return r;
		}
		
		double maximalFencedArea(vector<int> _fences)
		{
			fences=_fences;
			n=fences.size();
			for(int i=0;i<(1<<n);i++)
				cache[i]=-1;

			return rec((1<<n)-1);
		}
};

