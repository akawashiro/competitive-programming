#include <vector>
#include <queue>

#define OFFSET 100
using namespace std;

class HoleCakeCuts
{
	public:

		int cake[201][201];

		int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts)
		{
			for(int x=-100;x<=100;x++)
				for(int y=-100;y<=100;y++)
					cake[x+OFFSET][y+OFFSET]=-2;
			for(int x=-cakeLength;x<cakeLength;x++)
				for(int y=-cakeLength;y<cakeLength;y++)
					cake[x+OFFSET][y+OFFSET]=0;
			for(int x=-holeLength;x<holeLength;x++)
				for(int y=-holeLength;y<holeLength;y++)
					cake[x+OFFSET][y+OFFSET]=-2;

			for(int i=0;i<horizontalCuts.size();i++)
				for(int x=-100;x<=100;x++)
					for(int y=-100;y<=100;y++)
						if(cake[x+OFFSET][y+OFFSET]!=-2 && horizontalCuts[i]<=y)
							cake[x+OFFSET][y+OFFSET]++;
			for(int i=0;i<verticalCuts.size();i++)
				for(int x=-100;x<=100;x++)
					for(int y=-100;y<=100;y++)
						if(cake[x+OFFSET][y+OFFSET]!=-2 && verticalCuts[i]<=x)
							cake[x+OFFSET][y+OFFSET]++;
							
			int ans=0;
			for(int sx=0;sx<=200;sx++)
				for(int sy=0;sy<=200;sy++)
					if(cake[sx][sy]!=-2)
					{
						ans++;
						int color=cake[sx][sy];
						int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
						queue<int> que;
						que.push(sx*300+sy);

						while(!que.empty())
						{
							int x=que.front()/300;
							int y=que.front()%300;
							que.pop();

							if(x<0 || 200<x || y<0 || 200<y)
								continue;
							if(cake[x][y]!=color)
								continue;
							cake[x][y]=-2;
							for(int i=0;i<4;i++)
							{
								int xx=x+mv[i][0];
								int yy=y+mv[i][1];
								que.push(xx*300+yy);
							}
						}
					}
			return ans;
		}
};

