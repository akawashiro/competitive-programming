#include <vector>

using namespace std;

typedef long long LL;

class DivisibleByDigits
{
	public:

		bool OK(LL num,vector<LL> div)
		{
			for(int i=0;i<div.size();i++)
				if(num%div[i]!=0)
					return false;
			return true;
		}

		LL getContinuation(int _n)
		{
			LL n=_n;
			LL a,b,c;
			vector<LL> div;
			
			a=n;
			while(a!=0)
			{
				if(a%10!=0)
					div.push_back(a%10);
				a/=10;
			}

			for(a=1;a<1000000;a*=10)
			{
				b=n*a;
				for(c=0;c<a;c++)
					if(OK(b+c,div))
						return b+c;
			}
			return -1;
		}
};
