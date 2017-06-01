#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class DancingCouples
{
	public:

		vector <string> can;
		int bn,gn;
		int cache[11][11][(1<<10)];

		int rec(int b,int K,int left)
		{	
			int &r=cache[b][K][left];
			if(r!=-1)
				return r;
			if(K==0)
				return r=1;
			if(b==bn)
				return r=0;
			r=0;
			r+=rec(b+1,K,left);
			for(int g=0;g<gn;g++)
				if((left&(1<<g)) && can[b][g]=='Y')
					r+=rec(b+1,K-1,left&(~(1<<g)));
			return r;
		}

		int countPairs(vector<string> _canDance,int K)
		{
			can=_canDance;
			bn=can.size(),gn=can[0].size();
			memset(cache,-1,sizeof(cache));

			return rec(0,K,(1<<gn)-1);
		}

};

