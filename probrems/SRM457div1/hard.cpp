#include <algorithm>
#include <cstring>

typedef long long LL;
using namespace std;

class TheHexagonsDivOne
{
	public:

		int board[7];
		LL cache[200][200];

		LL C(int n,int r)
		{
			if(n<r)
				return 0;
			if(cache[n][r]!=-1)
				return cache[n][r];
			if(r==0)
				return cache[n][r]=1;
			return cache[n][r]=C(n,r-1)+C(n-1,r-1);
		}

		LL calc()
		{
			LL r=0;
			int o[7];
			for(int i=0;i<7;i++)
				o[i]=i;
			do
			{
				int bo[7];
				for(int i=0;i<7;i++)
					bo[i]=board[o[i]];
				bool b=true;
				for(int i=1;i<5 && b;i++)
					b=(b && bo[i-1]!=bo[i]);
				b=(b && bo[0]!=bo[5] && bo[4]!=bo[5]);
				for(int i=0;i<6 && b;i++)
					b=(b && bo[i]!=bo[6]);
				if(b)
					r++;
			}while(next_permutation(o,o+7));
			return r;
		}

		LL count(int n)
		{
			memset(cache,-1,sizeof(cache));
			LL ans=0;
			
			board[0]=0,board[1]=1,board[2]=2,board[3]=3,board[4]=4,board[5]=5,board[6]=6;
			printf("same=0 calc()=%lld\n",calc());
			ans+=C(n,7)*C(7,0)*calc()/6;
			
			board[0]=0,board[1]=0,board[2]=2,board[3]=3,board[4]=4,board[5]=5,board[6]=6;
			printf("same=1 calc()=%lld\n",calc());
			ans+=C(n,6)*C(6,1)*calc()/6;
			
			board[0]=0,board[1]=0,board[2]=2,board[3]=2,board[4]=4,board[5]=5,board[6]=6;
			printf("same=2 calc()=%lld\n",calc());
			ans+=C(n,5)*C(5,2)*calc()/6;

			board[0]=0,board[1]=0,board[2]=2,board[3]=2,board[4]=4,board[5]=4,board[6]=6;
			printf("same=3 calc()=%lld\n",calc());
			ans+=C(n,4)*C(4,3)*calc()/6;
			return ans;
		}
};

