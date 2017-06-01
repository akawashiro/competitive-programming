#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Mafia
{
	public:

		int n,mine;
		int responses[16][16];
		vector<int> guilt;
		vector<int> survivers;

		int rec()
		{
			int left=0;
			
			for(int i=0;i<n;i++)
				if(survivers[i])
					left++;
			if(!survivers[mine] || left<2)
				return 0;
			
			if(left%2==1)
			{
				int maxG=-(1<<28),rI=0;
				for(int i=0;i<n;i++)
					if(survivers[i] && maxG<guilt[i])
						maxG=guilt[i],rI=i;
				survivers[rI]=false;
				int r=rec();
				survivers[rI]=true;
				return r;
			}
			else
			{
				int r=0;
				for(int i=0;i<n;i++)
					if(mine!=i && survivers[i])
					{
						vector<int> g=guilt;
						for(int j=0;j<n;j++)
							guilt[j]+=responses[i][j];
						survivers[i]=false;
						r=max(r,rec()+1);
						survivers[i]=true;
						guilt=g;
					}
				return r;
			}
		}

		int play(vector <int> _guilt, vector <string> _responses, int playerIndex)
		{
			mine=playerIndex;
			n=_guilt.size();
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					char c=_responses[i][j];
					responses[i][j]=('a'<=c && c<='z')?-(c-'a'+1):(c-'A'+1);
				}

			vector<int> v(n,true);
			guilt=_guilt;
			survivers=v;
			
			return rec();
		}
};

