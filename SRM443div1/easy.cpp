#include <vector>
#include <algorithm>
using namespace std;

class CirclesCountry
{
	public:
		vector <int> X;
		vector <int> Y;
		vector <int> R;
		int n;

		bool isContain(int circleN,int x,int y)
		{
			int a=abs(x-X[circleN]),b=abs(y-Y[circleN]);
			return (a*a+b*b<=R[circleN]*R[circleN]);
		}

		int leastBorders(vector <int> _X, vector <int> _Y, vector <int> _R, int x1, int y1, int x2, int y2)
		{
			X=_X,Y=_Y;R=_R;
			X.push_back(0),Y.push_back(0),R.push_back(10000);
			n=X.size();
			vector<int> contain1;
			vector<int> contain2;
			while(1)
			{
				int minR=1000000,addN=n-1;
				for(int i=0;i<n;i++)
				{
					if(find(contain1.begin(),contain1.end(),i)!=contain1.end())
						continue;
					if(isContain(i,x1,y1))
						if(R[i]<minR)
							addN=i,minR=R[i];
				}
				contain1.push_back(addN);
				if(addN==n-1)
					break;
			}
			while(1)
			{
				int minR=1000000,addN=n-1;
				for(int i=0;i<n;i++)
				{
					if(find(contain2.begin(),contain2.end(),i)!=contain2.end())
						continue;
					if(isContain(i,x2,y2))
						if(R[i]<minR)
							addN=i,minR=R[i];
				}
				contain2.push_back(addN);
				if(addN==n-1)
					break;
			}
			reverse(contain1.begin(),contain1.end());
			reverse(contain2.begin(),contain2.end());
			int sameCount=0;
			for(int i=0;i<min(contain1.size(),contain2.size());i++)
				if(contain1[i]==contain2[i])
					sameCount++;
			return contain1.size()+contain2.size()-sameCount*2;
		}
};
