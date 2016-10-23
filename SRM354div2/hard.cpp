#include <vector>
using namespace std;

typedef long long LL;

class UnsealTheSafe
{
	public:
		LL countPasswords(int N)
		{
			vector<int> edge[10];

			edge[1].push_back(2);	edge[1].push_back(4);
			edge[2].push_back(1);	edge[2].push_back(3);edge[2].push_back(5);
			edge[3].push_back(2);	edge[3].push_back(6);
			
			edge[4].push_back(1);	edge[4].push_back(5);edge[4].push_back(7);
			edge[5].push_back(2);	edge[5].push_back(4);edge[5].push_back(6);
			edge[5].push_back(8);
			edge[6].push_back(3);	edge[6].push_back(5);edge[6].push_back(9);

			edge[7].push_back(0);	edge[7].push_back(4);edge[7].push_back(8);
			edge[8].push_back(5);	edge[8].push_back(7);edge[8].push_back(9);
			edge[9].push_back(6);	edge[9].push_back(8);

			edge[0].push_back(7);

			vector<LL> DP(10,1);
			for(int i=0;i<N-1;i++)
			{
				vector<LL> pre=DP;
				DP=vector<LL>(10,0);

				for(int j=0;j<10;j++)
					for(int k=0;k<(int)edge[j].size();k++)
						DP[edge[j][k]]+=pre[j];
			}

			LL ans=0;
			for(int i=0;i<10;i++)
				ans+=DP[i];

			return ans;
		}
};

