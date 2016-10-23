#include <algorithm>
#include <vector>
using namespace std;

class OlympicCandles
{
public:
int numberOfNights(vector <int> candles)
{
	int n=candles.size();
	int night;

	for(night=0;;night++)
	{	
		sort(candles.begin(),candles.end());
		reverse(candles.begin(),candles.end());
		
		if(candles[n-1]<0)
		{
			night--;
			break;
		}
		if(n<night)
			break;
		
		
		for(int i=0;i<night;i++)
			candles[i]--;
		
		for(int i=0;i<n;i++)
			printf("%4d ",candles[i]);
		printf("\n");
	}
	return night-1;
}
};
