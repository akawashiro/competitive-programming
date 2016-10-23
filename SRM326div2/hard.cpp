#include <queue>
#include <vector>
#include <string>

using namespace std;

class PoolFiller
{
	public:

		int BFS(vector<string> pool)
		{
			int h=pool.size(),w=pool[0].size();
			int r=0;
			int mv[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

			for(int sy=0;sy<h;sy++)
				for(int sx=0;sx<w;sx++)
					if(pool[sy][sx]=='.')
					{
						int extent=0;
						bool isSurrounded=true;

						queue<int> que;
						que.push(sy*100+sx);
						while(!que.empty())
						{
							int y=que.front()/100,x=que.front()%100;
							que.pop();

							if(y<0 || h<=y || x<0 || w<=x)
							{
								isSurrounded=false;
								continue;
							}
							if(pool[y][x]=='#')
								continue;
							pool[y][x]='#';
							extent++;
							for(int i=0;i<4;i++)
							{
								int yy=y+mv[i][0],xx=x+mv[i][1];
								que.push(yy*100+xx);
							}
						}

						if(isSurrounded)
							r+=extent;
					}

			return r;
		}

		int getCapacity(vector<string> layout)
		{
			int ans=0;
			int h=layout.size(),w=layout[0].size();
			for(char water='2';water<='9';water++)
			{
				vector<string> pool(h,string(w,'#'));
				for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						if(layout[i][j] < water)
							pool[i][j]='.';
				ans+=BFS(pool);
			}

			return ans;
		}
};

