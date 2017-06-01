#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<bool,vector<string> > KEY;

class ScoreDifference
{
	public:
		int board[4][4];
		int cache[2][(1<<16)];

		int ABS(int num)
		{
			return num<0 ? -num : num;
		}
		
		bool calc(int s,int y,int x)
		{
			int a=(y*4+x);
			return s & (1<<a);
		}

		int rec(bool isPlayer,int canMove)
		{
			int &r=cache[(isPlayer) ? 1 : 0][canMove];
			if(r!=(1<<28))
				return r;
			if(canMove==(1<<16)-1)
				return 0;
			
			if(isPlayer)
				r=-(1<<28);
			else
				r=(1<<28);

			for(int y=0;y<4;y++)
				for(int x=0;x<4;x++)
					if(!calc(canMove,y,x))
					{
						bool isCan=(y==0 || y==3 || x==0 || x==3);
						isCan=(isCan || (0<y && calc(canMove,y-1,x)) );
						isCan=(isCan || (y<3 && calc(canMove,y+1,x)) );
						isCan=(isCan || (0<x && calc(canMove,y,x-1)) );
						isCan=(isCan || (x<3 && calc(canMove,y,x+1)) );
						
						if(!isCan)
							continue;
						int c=canMove;
						c=(c | (1<<(y*4+x)) );
						
						if(isPlayer)
							r=max(r,rec(false,c)+board[y][x]);
						else
							r=min(r,rec(true,c)-board[y][x]);
					}

			return r;
		}

		int maximize(vector <string> input)
		{
			for(int i=0;i<4;i++)
			{
				stringstream ss(input[i]);
				for(int j=0;j<4;j++)
				{
					int a;
					ss >> a;
					board[i][j]=a;
					printf("%3d",a);
				}
				printf("\n");
			}

			for(int i=0;i<2;i++)
				for(int j=0;j<(1<<16);j++)
					cache[i][j]=(1<<28);
			
			printf("rec(true,0)=%d\n",rec(true,0));
			printf("rec(false,0)=%d\n",rec(false,0));
			
			int ans=0;
			ans=max(ans,rec(true,0));
			ans=max(ans,rec(false,0));

			return ans;
		}
};

