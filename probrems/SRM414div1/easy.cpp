#include <vector>
#include <climits>
using namespace std;

class Embassy
{
public:
int visaApplication(vector <int> forms, int dayLength, int openTime)
{
	int time=0,open,close,ans=INT_MAX;
	
	time-=forms[0];
	for(time=0;time<=dayLength;time++)
	{
		open=0,close=openTime;
		int a=time;
		for(int i=0;i<forms.size();i++)
		{
			time+=forms[i];
			while(!(time<=close))
				open+=dayLength,close+=dayLength;
			time=max(time,open);
		}
		ans=min(ans,time-a);
		time=a;
	}
	return ans;
}
};
