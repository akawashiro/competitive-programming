#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class PowerGame
{
	public:

		string winner(int size0, int size1)
		{
			int DP[10005];
			for(int num=0;num<10005;num++)
			{
				if(num==0)
					DP[num]=0;
				else
				{
					int w=10005,l=-1;
					for(int i=1;i*i<=num;i++)
					{
						if(DP[num-i*i]%2==0)
							w=min(w,DP[num-i*i]+1);
						else
							l=max(l,DP[num-i*i]+1);
					}
					if(w!=10005)
						DP[num]=w;
					else
						DP[num]=l;
				}
			}

			int r=min(DP[size0],DP[size1]);
			char s[100];
			string ans;
			if(r%2==1)
				sprintf(s,"Alan will win after %d moves",r);
			else
				sprintf(s,"Bob will win after %d moves",r);
			ans=s;
			return ans;

		}
};

