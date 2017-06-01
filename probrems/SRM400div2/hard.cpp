#include <string>
#include <vector>

using namespace std;

class LightedPanels
{
	public:
		
		int h,w;
		vector<string> board,tmp;

		int popCount(int _mask)
		{
			int r=0;
			for(int i=0;i<28;i++)
				if(_mask & (1<<i))
					r++;
			return r;
		}

		void toggle(int y,int x)
		{
			int mv[9][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
			for(int i=0;i<9;i++)
			{
				int yy=y+mv[i][0],xx=x+mv[i][1];
				if(0<=yy && yy<h && 0<=xx && xx<w)
				{
					char c=board[yy][xx];
					board[yy][xx]=(c=='.')?'*':'.';
				}
			}
			return;
		}

		int minTouch(vector<string> _board)
		{
			board=_board;
			h=board.size(),w=board[0].size();
			int ans=(1<<28);

			for(int row0=0;row0<(1<<w);row0++)
				for(int column0=0;column0<(1<<h);column0++)
				{
					int r=popCount(row0)+popCount(column0);
					tmp=board;
					for(int x=0;x<w;x++)
						if(row0 & (1<<x))
							toggle(0,x);
					for(int y=0;y<h;y++)
						if(column0 & (1<<y))
							toggle(y,0);
					for(int y=1;y<h;y++)
						for(int x=1;x<w;x++)
							if(board[y-1][x-1]=='.')
								toggle(y,x),r++;
					bool b=true;
					for(int y=0;y<h;y++)
						for(int x=0;x<w;x++)
							if(board[y][x]=='.')
								b=false;
					if(b)
						ans=min(ans,r);
					board=tmp;
				}

			return (ans==(1<<28))?-1:ans;
		}
};

