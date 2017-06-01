#include <string>
#include <queue>
#include <vector>

using namespace std;

class Q
{
	public:
		int x,y,visited;
		double safe;
};

class ColorfulMazeTwo
{
	public:

		double prob[50][50][(1<<7)];
		
		double getProbability(vector<string> maze,vector<int> trap)
		{
			int h=maze.size(),w=maze[0].size();
			int sx=0,sy=0,ey=0,ex=0;

			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					for(int k=0;k<(1<<7);k++)
						prob[i][j][k]=0.0;
					if(maze[i][j]=='$')
						sy=i,sx=j;
					if(maze[i][j]=='!')
						ey=i,ex=j;
				}

			queue<Q> que;
			Q q;
			q.y=sy,q.x=sx,q.visited=0,q.safe=1.0;
			que.push(q);

			while(!que.empty())
			{
				int x=que.front().x,y=que.front().y,visited=que.front().visited;
				double safe=que.front().safe;
				que.pop();
				
				if(x<0 || w<=x || y<0 || h<=y)
					continue;
				if(maze[y][x]=='#')
					continue;
					
				if('A'<=maze[y][x] && maze[y][x]<='G')
				{
					int m=maze[y][x]-'A';
					if((visited & (1<<m))==0)
					{	
						double d=(double)(100-trap[m])/100.0;
						safe*=d;
						visited = (visited | (1<<m));
					}
				}
				if(prob[y][x][visited] < safe)
				{
					prob[y][x][visited]=safe;

					int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
					for(int i=0;i<4;i++)
					{
						int yy=y+mv[i][0],xx=x+mv[i][1];
						q.y=yy,q.x=xx,q.visited=visited,q.safe=safe;
						que.push(q);
					}
					
					//printf("x=%d y=%d visited=%d safe=%lf\n",x,y,visited,safe);	
				}
			}

			double ans=0.0;
			for(int i=0;i<(1<<7);i++)
				ans=max(ans,prob[ey][ex][i]);
			return ans;
		}
};
