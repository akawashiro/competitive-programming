#include <vector>
using namespace std;

class CircleMarket{
		public:
				int makePurchases(vector <int> openTime, 
								vector <int> closeTime, int travelTime);
};

int CircleMarket::makePurchases(vector <int> openTime, 
				vector <int> closeTime, int travelTime)
{
		int n=openTime.size();
		int isbuyed[n];
		for(int i=0;i<n;i++)
				isbuyed[i]=false;
		for(int i=0,time=0;time<=1000000;i++,time+=travelTime){
				if(i==n)
						i=0;
				if(!isbuyed[i] && openTime[i]<=time && time<=closeTime[i])
						isbuyed[i]=true;
		}
		int nbuyed=0;
		for(int i=0;i<n;i++)
				if(isbuyed[i])
						nbuyed++;
		return nbuyed;
}

