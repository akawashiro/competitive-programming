#include <string>
#include <vector>
#include <cmath>
using namespace std;

class FindingSquareInTable
{
	public:

		int height,width;

		int num(int y,int x,int ydiff,int xdiff,int seq,vector<string> table)
		{
			int n=0;
			for(int i=0;i<seq;i++)
			{
				if(0<=y && y<height && 0<=x && x<width)
				{
					n*=10;
					n+=table[y][x];
				}
				else
				{
					return -1;
				}
				y+=ydiff;
				x+=xdiff;
			}
			return n;
		}

		int findMaximalSquare(vector <string> table)
		{
			height=table.size();
			width =table[0].size();
			for(int i=0;i<height;i++)
				for(int j=0;j<width;j++)
					table[i][j]-='0';

			int ans=-1;

			for(int y=0;y<height;y++)
				for(int x=0;x<width;x++)
					for(int ydiff=-8;ydiff<=8;ydiff++)
						for(int xdiff=-8;xdiff<=8;xdiff++)
						{
							if(ydiff==0 && xdiff==0)
								continue;
							for(int seq=1;seq<=9;seq++)
							{
								int n=num(y,x,ydiff,xdiff,seq,table);
								int a=(int)sqrt(n);
								if(a*a==n)
									ans=max(ans,n);
							}
						}

			return ans;
		}
};
