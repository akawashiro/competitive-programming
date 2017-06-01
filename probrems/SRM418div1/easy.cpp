#include <vector>
#include <algorithm>
using namespace std;

class TwoLotteryGames
{
	public:
		double getHigherChanceGame(int n, int m, int k)
		{
			int total=0,hit=0;
			int num[8];
			for(int i=1;i<9;i++)
				num[i-1]=i;
			do
			{
				int h=0;
				total++;
				for(int i=0;i<m;i++)
					if(num[i]<=m)
						h++;
				if(k<=h)
					hit++;
				reverse(num+m,num+n);
			}while(next_permutation(num,num+n));

			return (double)hit/(double)total;
		}
};

