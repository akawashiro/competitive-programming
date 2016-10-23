#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

#define OFFSET 3
using namespace std;

class HexagonalBattlefieldEasy 
{
	public:
	int field[8][8];

	int DFS(int pos)
	{
		int x=pos%7,y=pos/7,r=0;

		if(x==6 && y==6)
			r = (field[x][y]==1) ? 1 : 0;
		else if(field[x][y]==1)
			r = DFS(pos+1);
		else
		{
			field[x][y]=1;
			if(field[x+1][y]==0)
			{
				field[x+1][y]=1;
				r+=DFS(pos+1);
				field[x+1][y]=0;
			}
			if(field[x+1][y+1]==0)
			{
				field[x+1][y+1]=1;
				r+=DFS(pos+1);
				field[x+1][y+1]=0;
			}
			if(field[x][y+1]==0)
			{
				field[x][y+1]=1;
				r+=DFS(pos+1);
				field[x][y+1]=0;
			}
			field[x][y]=0;
		}

		return r;
	}

	int countArrangements(vector <int> X, vector <int> Y, int N)
	{
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				field[i][j]=1;

		for(int i=-N+1;i<=0;i++)
			for(int j=0;j<N;j++)
			{
				field[i+OFFSET][i+j+OFFSET]=0;
				field[i+j+OFFSET][i+OFFSET]=0;
			}
		
		for(int i=N-1;0<=i;i--)
			for(int j=0;j<N;j++)
			{
				field[i+OFFSET][i-j+OFFSET]=0;
				field[i-j+OFFSET][i+OFFSET]=0;
			}
			
				for(int i=0;i<X.size();i++)
			field[X[i]+OFFSET][Y[i]+OFFSET]=1;

		int ans=0;
		ans=DFS(0);
		return ans;
	}
};
