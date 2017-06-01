#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class BattleshipChecker
{
	public:

		string checkBoard(vector <string> board)
		{
			for(int y=1;y<9;y++)
				for(int x=1;x<9;x++)
					if(board[y][x]=='X')
						if(board[y-1][x-1]=='X' ||	board[y-1][x+1]=='X' ||
								board[y+1][x-1]=='X' ||	board[y+1][x+1]=='X')
							return "REJECTED";

			for(int y=0;y<10;y++)
				for(int x=0;x<10;x++)
					if(board[y][x]=='X')
					{
						if(0<=y-1 && board[y-1][x]=='X' && 0<=x-1 && board[y][x-1]=='X')
							return "REJECTED";
						if(0<=y-1 && board[y-1][x]=='X' && x+1<10 && board[y][x+1]=='X')
							return "REJECTED";
						if(y+1<10 && board[y+1][x]=='X' && 0<=x-1 && board[y][x-1]=='X')
							return "REJECTED";
						if(y+1<10 && board[y+1][x]=='X' && x+1<10 && board[y][x+1]=='X')
							return "REJECTED";
					}

			vector<int> ships;
			for(int y=0;y<10;y++)
				for(int x=0;x<10;x++)
					if(board[y][x]=='X')
					{
						int yy=y,xx=x,len=0;
						if(y<9 && board[y+1][x]=='X')
							while(yy<10 && board[yy][xx]=='X')
							{
								len++;
								board[yy][xx]='S';
								yy++;
							}
						else if(x<9 && board[y][x+1]=='X')
							while(xx<10 && board[yy][xx]=='X')
							{
								len++;
								board[yy][xx]='S';
								xx++;
							}
						else
						{
							board[yy][xx]='S';
							len=1;
						}
						ships.push_back(len);
					}

			sort(ships.begin(),ships.end());
			if(ships.size()!=10)
					return "REJECTED";
			for(int i=0;i<10;i++)
			{
				if(0<=i && i<4 && ships[i]!=1)
					return "REJECTED";
				if(4<=i && i<7 && ships[i]!=2)
					return "REJECTED";
				if(7<=i && i<9 && ships[i]!=3)
					return "REJECTED";
				if(i==9 && ships[i]!=4)
					return "REJECTED";
			}

			int point=0;
			for(int y=0;y<10;y++)
			{
				int x;
				for(x=0;x<10;x++)
					if(board[y][x]!='.')
						break;
				if(x==10)
					point++;
			}
			for(int x=0;x<10;x++)
			{
				int y;
				for(y=0;y<10;y++)
					if(board[y][x]!='.')
						break;
				if(y==10)
					point++;
			}

			stringstream ss;
			ss << "ACCEPTED, " << point << " POINTS";
			return ss.str();
		}
};

