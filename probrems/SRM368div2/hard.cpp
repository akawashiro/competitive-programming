#include <cstring>
#include <set>
#include <string>
#include <vector>

using namespace std;

class JumpingBoard
{
	public:

		int n,start;
		vector<int> map[2500];
		bool can[2500][2500];
		int cache[2500];

		void check(int p)
		{
			if(!can[start][p])
			{
			can[start][p]=true;
			for(int i=0;i<(int)map[p].size();i++)
				check(map[p][i]);
			}
		}

		int DFS(int now)
		{
			if(cache[now]!=-1)
				return cache[now];
			int r=0;
			for(int i=0;i<map[now].size();i++)
				r=max(r,DFS(map[now][i]));
			return cache[now]=r+1;
		}

		int maxJumps(vector <string> board)
		{
			int h=board.size(),w=board[0].size();
			memset(can,false,sizeof(can));
			memset(cache,-1,sizeof(cache));
			n=h*w;

			for(int y=0;y<h;y++)
				for(int x=0;x<w;x++)
					if(board[y][x]!='H')
					{
						int p=y*w+x;
						int d=board[y][x]-'0';
						int mv[4][2]={{d,0},{-d,0},{0,d},{0,-d}};
						for(int i=0;i<4;i++)
						{
							int yy=y+mv[i][0],xx=x+mv[i][1];
							int pp=yy*w+xx;
							if(0<=yy && yy<h && 0<=xx && xx<w && board[yy][xx]!='H')
								map[p].push_back(pp);
						}
					}
					
			for(int i=0;i<n;i++)
			{
				start=i;
				check(i);
			}
			
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(can[0][i] && can[i][j] && can[j][i])
						return -1;

			int ans=DFS(0);
			return ((1<<28)<=ans)?-1:ans;
		}
};

