#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

class ReverseUnnaturalBaseConversion 
{
	public:
		string convertToBase(int _x, int _b)
		{
			LL x=_x,b=_b;
			string pre,ans;
			if(0<b && x<0)
			{
				pre="-";
				x=-x;
			}

			LL b1=1;
			while(x!=0)
			{
				int num=0;
				while(x%(b1*b)!=0)
				{
					x-=b1;
					num++;
				}
				ans+='0'+num;
				b1*=b;
			}

			reverse(ans.begin(),ans.end());
			ans=pre+ans;
			if(ans=="-" || ans=="-0" || ans=="")
				ans="0";

			return ans;
		}
};

