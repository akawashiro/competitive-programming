#include <vector>
#include <string>
using namespace std;

int move[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};;

class KnightsTour
{
	public:

		int acNumber(vector<string> board,int x,int y)
		{
			if( (!(0<=x && x<8 && 0<=y && y<8)) || board[y][x]!='.')
				return 100;
			int r=0;
			for(int i=0;i<8;i++)
			{
				int x1=x+move[i][0];
				int y1=y+move[i][1];
				if(0<=x1 && x1<8 && 0<=y1 && y1<8 && board[y1][x1]=='.')
					r++;
			}
			return r;
		}

		int visitedPositions(vector <string> board)
		{
			int x=0,y=0;
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(board[i][j]=='K')
						y=i,x=j,board[i][j]='V';
			while(1)
			{
				int ac=100;
				int nm=0;
				for(int i=0;i<8;i++)
					if(acNumber(board,x+move[i][0],y+move[i][1]) < ac)
					{
						ac=acNumber(board,x+move[i][0],y+move[i][1]);
						nm=i;
					}
				if(ac==100)
					break;
				board[y+move[nm][1]][x+move[nm][0]]='V';
				x+=move[nm][0];
				y+=move[nm][1];
			}

			int ans=0;
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(board[i][j]=='V')
						ans++;
			return ans;
		}
};
