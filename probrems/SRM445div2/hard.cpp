#include <vector>
#include <string>

using namespace std;

class TheLockDivTwo 
{
	public:
		string password(int n, int k)
		{
			int pass=0;
			vector<bool> isUsed((1<<n),false);

			for(int day=0;day<k-1;day++)
			{
				isUsed[pass]=true;

				int p;
				for(p=0;p<(1<<n);p++)
					if(!isUsed[p])
					{
						bool 1to0=false,0to1=false;
						for(int i=0;i<n;i++)
						{
							if( (pass&(1<<i)) && !(p&(1<<i)) )
								1to0=true;
							if( !(pass&(1<<i)) && (p&(1<<i)) )
								0to1=true;
						}
						if(1to0 ^ 0to1)
						{
							pass=p;
							break;
						}
					}
			}

			string ans(n,'0');
			for(int i=0;i<n;i++)
				if(pass&(1<<i))
					ans[n-1-i]='1';

			return ans;
		}
};

