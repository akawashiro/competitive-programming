#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class InstantRunoffVoting
{
	public:
		int winner(vector <string> voters)
		{
			int n=voters[0].size();
			int boder=(int)voters.size()/2+1;
			vector<int> candiate(n,0);

			while(1)
			{
				//for(int i=0;i<n;i++)
				//	printf("%4d",candiate[i]);
				//printf("\n");
				
				for(int i=0;i<voters.size();i++)
					for(int j=0;j<n;j++)
						if(candiate[voters[i][j]-'0']!=-2)
						{
							candiate[voters[i][j]-'0']++;
							break;
						}

				int ma=0,mi=(1<<30);
				for(int i=0;i<n;i++)
				{
					if(-2<candiate[i] && candiate[i]<mi)
						mi=candiate[i];
					if(ma<candiate[i])
						ma=candiate[i];
				}

				if(boder<=ma)
				{
					int r=0;
					for(r=0;r<n;r++)
						if(candiate[r]==ma)
							return r;
				}
				for(int i=0;i<n;i++)
					if(candiate[i]==mi)
						candiate[i]=-2;
				if(n-count(candiate.begin(),candiate.end(),-2) == 0)
					return -1;


				for(int i=0;i<n;i++)
					if(candiate[i]!=-2)
						candiate[i]=0;
			}
			return -1;
		}
};
