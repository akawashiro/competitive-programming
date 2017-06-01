#include <algorithm>
#include <cstring>
#include <vector>

typedef long long LL;
using namespace std;

class DiceGames 
{
	public:

		int n;
		LL cache[50][50];
		vector<int> sides;

		LL rec(int k,int least)
		{
			LL &r=cache[k][least];
			if(r!=-1)
				;
			else if(k==n)
				r=1;
			else
			{
				r=0;
				for(int i=least;i<=sides[k];i++)
					r+=rec(k+1,i);
			}
			return r;
		}

		LL countFormations(vector<int> _sides)
		{
			sides=_sides;
			n=sides.size();
			sort(sides.begin(),sides.end());

			memset(cache,-1,sizeof(cache));
			return rec(0,1);
		}
};

