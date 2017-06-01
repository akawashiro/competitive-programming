//this is copy ,too.
#include <vector>
using namespace std;

class CutSticks{
	public:

		bool isCanDevide(vector<int> sticks,int C,int K,double l)
		{
			int n=sticks.size();
			int k=K;
			for(int i=0;i<n;i++)
				if(l<sticks[i]){
					int a=min(C,int(sticks[i]/l)-1);
					C-=a;
					k+=a+1;
				}
			return (K<=k);
		}

		double maxKth(vector <int> sticks, int C, int K)
		{
			double a=0;
			double b=1000000000;

			for(int i=0;i<100;i++)
			{
				double c=(a+b)/2;
				if(isCanDevide(sticks,C,K,c))
					a=c;
				else
					b=c;
			}

			return (a+b)/2;
		}
};
