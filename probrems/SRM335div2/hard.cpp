#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class MinimumVariancePartition
{
	public:

		vector<int> sample;
		int n;

		double calc(int s,int e)
		{
			double ave=0;
			for(int i=s;i<e;i++)
				ave+=(double)sample[i];
			ave/=(double)(e-s);
			
			double r=0;
			for(int i=s;i<e;i++)
				r+=abs(sample[i]-ave)*abs(sample[i]-ave);
			return r/(double)(e-s);
		}

		double cache[50][50+1];
		
		double rec(int start,int k)
		{
			double *c=&cache[start][k];
			
			if(-1<*c)
				return *c;
				
			if(k==1)
				return *c=calc(start,n);

			double r=(1<<28);
			for(int i=start;i<=n-k;i++)
				r=min(r,calc(start,i+1)+rec(i+1,k-1));
			return *c=r;
		}

		double minDev(vector <int> mixedSamples, int k)
		{
			sample=mixedSamples;
			sort(sample.begin(),sample.end());
			n=sample.size();
			for(int i=0;i<50;i++)
				for(int j=0;j<51;j++)
					cache[i][j]=-2;

			return rec(0,k);
		}
};

