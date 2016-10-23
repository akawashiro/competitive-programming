#include <cstring>
#include <string>
#include <vector>

typedef long long LL;
using namespace std;


class UNIONFIND
{
	public:
	vector<int> date;
	vector<int> scale;
	UNIONFIND(int n)
	{
		for(int i=0;i<n;i++)
		{
			date.push_back(i);
			scale.push_back(1);
		}
	}
	int root(int n)
	{
		if(date[n]==n)
			return n;
		else
			return date[n]=root(date[n]);
	}
	void unionSet(int x,int y)
	{
		if(root(x)==root(y))
			return;
		scale[root(y)]+=scale[root(x)];
		scale[root(x)]=0;
		date[root(x)]=date[root(y)];
	}
	int unionSize(int n)
	{
		return scale[root(n)];
	}
};

class HexagonPuzzle
{
	public:
	
		LL MOD;

		int theCount(vector<string> board)
		{
			MOD=1000000007;
			int n=board.size();
			UNIONFIND U(n*n);

			for(int y1=0;y1<n;y1++)
				for(int x1=0;x1<=y1;x1++)
				{
					int y2=y1+1,y3=y1+1,x2=x1,x3=x1+1;
					if(0<=y2 && y2<n && 0<=x2 && x2<=y2 && 
							0<=y3 && y3<n && 0<=x3 && x3<=y3
							&& board[y1][x1]=='.' && board[y2][x2]=='.'
							&& board[y3][x3]=='.')
						U.unionSet(y1*n+x1,y2*n+x2),U.unionSet(y1*n+x1,y3*n+x3);
					y2=y1,y3=y1+1,x2=x1+1,x3=x1+1;
					if(0<=y2 && y2<n && 0<=x2 && x2<=y2 && 
							0<=y3 && y3<n && 0<=x3 && x3<=y3
							&& board[y1][x1]=='.' && board[y2][x2]=='.'
							&& board[y3][x3]=='.')
						U.unionSet(y1*n+x1,y2*n+x2),U.unionSet(y1*n+x1,y3*n+x3);
				}

			LL ans=1;
			LL fact[3000];
			fact[2]=1;
			for(LL i=3;i<3000;i++)
				fact[i]=fact[i-1]*i%MOD;
			
			//printf("here\n");
			
			for(int i=0;i<n*n;i++)
			{
				LL a=0;
				for(int j=0;j<n*n;j++)
					if(U.root(j)==i)
						a++;
				//printf("a=%d\n",a);
				if(2<a)
					ans=(ans*fact[a])%MOD;
			}
			return (int)ans;
		}
};
