#include <vector>
using namespace std;

class EquilibriumPoints
{
	public:
		vector <double> getPoints(vector <int> x, vector <int> m)
		{
			int n=x.size();
			vector<double> ans(n-1);
			for(int i=0;i<n-1;i++)
			{
				double b=x[i],c=x[i+1];
				for(int j=0;j<50;j++)
				{
					double p=(b+c)/2.0;
					double left=0,right=0;
					for(int k=0;k<n;k++)
					{
						double d=p-(double)x[k];
						double f=m[k]*10.0/d/d;
						if(0<d)
							left+=f;
						else
							right+=f;
					}
					if(left<right)
						c=p;
					else
						b=p;
				}
				ans[i]=b;
			}
			return ans;
		}
};
